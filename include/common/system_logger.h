#ifndef SYSTEM_LOGGER_H
#define SYSTEM_LOGGER_H

typedef enum {
    COMP_AUTH,
    COMP_TRANSACTION,
    COMP_ACC_STATUS,
    COMP_ACC_CREDS,
    COMP_ACC_NOTIF
} SystemComponent;

typedef enum {
    INFO,
    WARN,
    ERROR,
} SysLogLevel;

void log_system_operations(SysLogLevel level, SystemComponent comp, int enum_code);
void write_transac_log(const char* status, const char* op, int acc1, int acc2, long long amount);

#endif