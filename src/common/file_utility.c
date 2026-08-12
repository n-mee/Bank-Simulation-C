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

void write_transac_log(const char* status, const char* op, int acc1, int acc2, long long amount) {
    if (verify_dir_status("log") == -1) {
        perror("[!] ERROR: Failed to find parent folder.\n");
        return;
    }

    FILE* log = fopen("log/bank_history.log", "a");
    if (log == NULL) {
        perror("[!] ERROR: Cannot create/found the file.\n");
    }

    time_t raw_time = time(NULL);
    struct tm* time_info = localtime(&raw_time);

    char time_instr[32];
    strftime(time_instr, sizeof(time_instr), "%Y-%m-%d %H:%M:%S",time_info);

    fprintf(log, "[%s]\n", time_instr);
    fprintf(log, " ----> [%s] Operation: %s | Src: %d -> Dst: %d | Amt: $%lld.%02lld\n",
        status, op, acc1, acc2, amount / 100, amount % 100);       
    fclose(log);
}