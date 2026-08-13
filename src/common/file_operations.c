#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include "common/file_utility.h"
#include "common/file_operations.h"

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