#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include "common/file_utility.h"
#include "common/file_operations.h"

/**
 * @brief a 32bit crc checksum for file integrity
 * @param data a dynamic data reference for account model struct
 * @param total_accounts counst the total exisint account in database
 * @param struct_size passed the size of the account model struct
 * @return returns a custom 32bit uint value to embedd at the file
 */
static uint32_t do_crc32(const void* data, size_t total_accounts, size_t struct_size) {
    size_t total_bytes = total_accounts * struct_size;
    const uint8_t *byte_ptr = (const uint8_t *)data;

    uint32_t crc = 0xFFFFFFFF;

    for (size_t i = 0; i < total_bytes; i++) {
        crc ^= byte_ptr[i];

        for (int j = 0; j < 8; j++) {
            uint32_t mask = -(crc & 1);
            crc = (crc >> 1) ^ (0XEDB88320 & mask);
        }
    }
    return ~crc;
}

// TODO: read header file before touching this code
FileStatus load_from_file(BankDatabase *db){

    FILE *data = fopen("data/database.bin", "rb");
    if (data == NULL) return FILE_NOT_FOUND;

    uint32_t saved_checksum = 0;
    fread(&saved_checksum, sizeof(uint32_t), 1, data);

    fread(&db->account_count, sizeof(db->account_count), 1, data);
    if (db_expand(db, db->account_count) == -1) {
        fclose(data);
        return FILE_WRITE_FAILED;
    }

    fread(db->records, sizeof(Account), db->account_count, data);
    fclose(data);

    uint32_t do_checksum = do_crc32(db->records, db->account_count, sizeof(Account));

    if (do_checksum != saved_checksum) {
        db->account_count = 0;
        return FILE_CORRUPTED;
    }

    return FILE_OK;
}

// TODO: Read header file according to this function name
FileStatus save_to_file(BankDatabase *db){

    // Checks for directory avaibility
    if (verify_dir_status("data") == -1) {
        return FILE_WRITE_FAILED;
    }

    // Initiates the creation of database file
    FILE *data = fopen("data/database.bin", "wb");
    if (data == NULL) {
        return FILE_PERMISSION_DENIED;
    }

    uint32_t placeholder = 0;
    fwrite(&placeholder, sizeof(uint32_t), 1, data);

    fwrite(&db->account_count, sizeof(db->account_count), 1,data);
    fwrite(db->records, sizeof(Account), db->account_count, data);

    uint32_t real_checksum = do_crc32(db->records, db->account_count, sizeof(Account));

    fseek(data, 0, SEEK_SET);
    fwrite(&real_checksum, sizeof(uint32_t), 1, data);

    fclose(data);
    return FILE_OK;
}