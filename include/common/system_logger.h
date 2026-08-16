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
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
} SysLogLevel;

/**
 * @brief logs system operations with dates, system level, type and its enum code
 * @param level reference for severity type
 * @param comp reference for what operation went wrong
 * @param enum_code raw code status used to track the return error
 */
void log_system_operations(SysLogLevel level, SystemComponent comp, int enum_code);

/**
 * @brief prevents data loss by sudden death in terminal by logging transaction operation
 * @param status pointer referenc for operation confirmation (e.g COMMIT or PENDING)
 * @param op operation type reference
 * @param acc1 account id reference
 * @param acc2 second account id reference
 * @param amount balance used during transaction
 */
void write_transac_log(const char* status, const char* op, int acc1, int acc2, long long amount);

#endif