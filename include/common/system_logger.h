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

#endif