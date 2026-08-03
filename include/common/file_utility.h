#ifndef FILE_UTILITY_H
#define FILE_UTILITY_H

// Platform Indipendent syscalls() for different OS
#if defined(_WIN32) || defined(_WIN64)
    #include <direct.h> // Windows dir header
    #define make_dir(path) _mkdir(path)
#elif defined(__linux__) || defined(__APPLE__)
    #include <sys/stat.h> // Linux/macOS dir header
    #include <sys/types.h>
    #define make_dir(path) mkdir(path, 0755)
#endif

#include <stdio.h>
#include <errno.h>
/**
 * @brief Initializes the directory given from parameter
 * @param path String reference for directory to be evaluated
 * @return 0 if successful, -1 if the initialization or creation failed.
 */
int verify_dir_status(const char* path);

#endif