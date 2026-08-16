#include <stdio.h>
#include <time.h>
#include "common/file_utility.h"
#include "common/system_logger.h"
#include "services/auth_service.h"
#include "services/account_service.h"
#include "services/transaction_service.h"

static const char* sys_cvrttostr_auth(int status) {
    switch (status) {
        case AUTH_ERR_SESSION_NULL: return "AUTH_CRITICAL_SESSION_IS_NULL";
        case AUTH_ERR_DB_FULL: return "AUTH_DATABASE_CAPACITY_MAXIMUM_EXCEEDED";
        case AUTH_ERR_NOT_FOUND: return "AUTH_ACCOUNT_NOT_FOUND";
        case AUTH_ERR_BAD_PIN: return "AUTH_PIN_INVALID";
        case AUTH_ERR_CLOSED: return "AUTH_INACTIVE_ACCOUNT";
        default: return "AUTH_SYS_FLOW_OK";
    }
}

static const char* sys_cvrttostr_transac(int status) {
    switch (status) {
        case TXN_ERR_NULL: return "TRANSACTION_CRITICAL_SESSION_NULL";
        case TXN_BAL_OVERFLOW: return "TRANSACTION_EXCEEDED_64BIT_INTEGER_BALANCE";
        case TXN_ERR_RECEIVER_NOT_FOUND: return "TRANSACTION_RECEIVER_ID_MISSING";
        case TXN_ERR_SELF_TRANSFER: return "TRANSACTION_SELF_TRANSFER_AUDIT";
        case TXN_OPERATION_SUCCESS: return "TRANSACTION_SYS_FLOW_OK";
        default: return "TRANSACTION_GENERIC_CODE";
    }
}

static const char* sys_cvrttostr_status(int status) {
    switch (status) {
        case STATUS_OPERATION_ERR_SESSION_NULL: return "STATUS_CRITICAL_SESSION_NULL";
        case STATUS_OPERATION_ERR_CLOSE_INCOMPATIBLE: return "STATUS_ACCOUNT_STATE_INCOMPATIBILITY";
        case STATUS_OPERATION_SUCCESS: return "STATUS_SYS_FLOW_OK";
        default: return "STATUS_GENERIC_CODE";
    }
}

static const char* sys_cvrttostr_notif(int status) {
    switch (status) {
        case NOTIF_ERR_SESSION_NULL: return "NOTIF_CRITICAL_SESSION_EMPTY";
        case NOTIF_WARN_ALREADY_SET: return "NOTIF_FLAG_ALREADY_SET";
        default: return "NOTIF_SYS_FLOW_OK";
    }
}

static const char* sys_cvrttostr_creds(int status) {
    switch (status) {
        case CRED_ERR_ACCOUNT_NULL: return "CREDENTIALS_CRITICAL_ACCOUNT_NULL";
        case CRED_ERR_UPDATE_OPERATION_FAIL: return "CREDENTIALS_CRITICAL_OPERATION_FAIL";
        case CRED_ERR_INPUT_STR_ERROR: return "CREDENTIALS_STRING_INPUT_ERROR";
        case CRED_OPERATION_SUCCESS: return "CREDENTIALS_SYS_FLOW_OK";
        default: return "CREDENTIALS_GENERIC_CODE";
    }
}

void log_system_operations(SysLogLevel level, SystemComponent comp, int enum_code) {
    if (verify_dir_status("log") == -1) return;

    FILE* sys_log = fopen("log/sys_log.log", "a");
    if (sys_log == NULL) return;

    time_t raw_time = time(NULL);
    struct tm* time_info = localtime(&raw_time);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);

    const char* comp_label = "CORE";
    const char* status_name = "UNKNOWN_SYS_CODE";

    if (comp == COMP_AUTH) {
        comp_label = "AUTHENTICATION";
        status_name = sys_cvrttostr_auth(enum_code);
    } else if (comp == COMP_TRANSACTION) {
        comp_label = "TRANSACTION_ENGINE";
        status_name = sys_cvrttostr_transac(enum_code);
    } else if (comp == COMP_ACC_STATUS) {
        comp_label = "ACCOUNT_MANAGEMENT";
        status_name = sys_cvrttostr_status(enum_code);
    } else if (comp == COMP_ACC_CREDS) {
        comp_label = "ACCOUNT_MANAGEMENT";
        status_name = sys_cvrttostr_creds(enum_code);
    } else if (comp == COMP_ACC_NOTIF) {
        comp_label = "ACCOUNT_MANAGEMENT";
        status_name = sys_cvrttostr_notif(enum_code);
    }

    const char* log_levels[] = {"INFO", "WARNING", "ERROR"};

    fprintf(sys_log, "[%s] [%s] [%s]: Technical_Code_Token -> %s (Raw ID: %d)\n", 
        time_str, log_levels[level], comp_label, status_name, enum_code);

    fclose(sys_log);
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