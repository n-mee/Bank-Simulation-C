#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <stdint.h>
#include "common/file_utility.h"

int verify_dir_status(const char* path) {
    // Checks if the return value of a system call is succesful
    if (make_dir(path) == -1) {
        // Throws an error if the returning error is not FILE_FOUND
        if (errno != EEXIST) {
            perror("[!] ERROR: Failed to create directory!\n");
            return -1;
        }
    }
    return 0;
}

uint32_t do_crc32(const void* data, size_t total_accounts, size_t struct_size) {
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