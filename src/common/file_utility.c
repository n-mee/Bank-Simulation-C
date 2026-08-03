#include "utils/file_utility.h"
#include <stdio.h>
#include <errno.h>

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