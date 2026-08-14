#include "cli/display_error_msg.h"
#include <stdio.h>

void invalid_integer_value(ParseExitResult status) {
    switch(status) {
        case ERR_INVALID_INT: printf("[!] ERROR: Input does not start with a number.\n"); break;
        case ERR_NULL_PTR: printf("[!] ERROR: Input returned a Null pointer.\n"); break;
        case ERR_TRAILING_GARBAGE: printf("[!] ERROR: Found trailing garbage characters after a number.\n"); break;
        default: break;
    }
}

void invalid_double_input(ParseExitResult status) {
    switch (status) {
        case ERR_OVERFLOW: printf("[!] ERROR: Cannot detect a number.\n"); break;
        case ERR_NEGATIVE: printf("[!] ERROR: Number cannot be negative.\n"); break;
        case ERR_NULL_PTR: printf("[!] ERROR: Input returned a Null pointer.\n"); break;
        case ERR_TRAILING_GARBAGE: printf("[!] ERROR: Found trailing garbage characters after a number.\n"); break;
        default: break;
    }
}

void invalid_bool_value(YesNoResult status) {
    switch (status) {
        case ERR_INVALID_INPUT: printf("[!] ERROR: Cannot detect a 'yes' or 'no' input.\n"); break;
        case ERR_INPUT_EXCEED_RANGE: printf("[!] ERROR: Text exceeds memory limits.\n"); break;
        default: break;
    }
}

void invalid_string_value(ParsedStringResult status) {
    switch (status) {
        case ERR_EMPTY_STRING: printf("[!] ERROR: Input cannot be empty.\n"); break;
        case ERR_EXCEEDED_MAX_SIZE: printf("[!] ERROR: Text exceeds memory limits.\n"); break;
        case ERR_STRING_NULL_PTR: printf("[!] ERROR: String referrence is pointed to NULL.\n"); break;
        default: break;
    }
}

void account_operation_error(Credentials status) {
    switch (status) {
        case ERR_INVALID_PIN: printf("[!] ERROR: Wrong Pin.\n"); break;
        case ERR_MISMATCH_PIN: printf("[!] ERROR: Pin doesn't match the credentials.\n"); break;
        case ERR_INPUT_STR_ERROR: printf("[!] ERROR: Input exceeded buffer size.\n"); break;
        case ERR_UPDATE_OPERATION_FAIL: printf("[!] ERROR: Something wrong happened.\n"); break;
        case OPERATION_SUCCESS:
        default: break;
    }
}

void account_notification_fail(NotificationsStatus status) {
    if (status == NOTIF_WARN_ALREADY_SET) {
        printf("[!] WARN: Alert is already set to that state.\n");
        return;
    }

    if (status == NOTIF_ERR_SESSION_NULL) {
        printf("[!] ERROR: Active session cannot be found.\n");
        return;
    }
}

void account_state_error(AccountStateStatus status) {
    switch (status) {
        case STATUS_OPERATION_ERR_CLOSE_INCOMPATIBLE: printf("[!] ERROR: Cannot freeze an account that is already closed.\n"); break;
        case STATUS_OPERATION_ERR_OUT_OF_RANGE: printf("[!] ERROR: Limit is not in the 10k - 50k range.\n"); break;
        case STATUS_OPERATION_ERR_SESSION_NULL: printf("[!] ERROR: Session cannot be found.\n"); break;
        case STATUS_OPERATION_WARN_ALREADY_SET: printf("[!] WARN: Your account is already set to that state.\n"); break;
        case STATUS_OPERATION_SUCCESS:
        default: break;
    }
}

void auth_operation_error(AuthStatus status) {
    switch (status) {
        case AUTH_ERR_BAD_PIN: printf("[!] ERROR: Invalid PIN or PIN doesn't match the account's pin.\n"); break;
        case AUTH_ERR_CLOSED: printf("[!] ERROR: Cannot login to an account that is CLOSED.\n"); break;
        case AUTH_ERR_DB_FULL: printf("[!] ERROR: Account database limit is full.\n"); break;
        case AUTH_ERR_NOT_FOUND: printf("[!] ERROR: Account ID cannot be found\n"); break;
        case AUTH_ERR_SESSION_NULL: printf("[!] ERROR: Session is empty or NULL.\n"); break;
        default: break;
    }
}

void account_transaction_fail(TransactionStatus status) {
    switch (status) {
        case TXN_INVALID_PIN:
            printf("[!] ERROR: Request Canceled. Invalid security input format.\n");
            break;
        case TXN_MISMATCH_PIN:
            printf("[!] ERROR: Access Denied. PIN authentication failed.\n");
            break;
        case TXN_INVALID_BAL:
            printf("[!] ERROR: Execution Aborted. Transaction amount must be above 0.\n");
            break;
        case TXN_INSUFFICIENT_BAL:
            printf("[!] ERROR: Denied. Current Balance is insufficient.\n");
            break;
        case TXN_BAL_OVERFLOW:
            printf("[!] ERROR: Operational Abort. You must be elon musk's great great grandfather.\n");
            break;
        case TXN_ERR_RECEIVER_NOT_FOUND:
            printf("[!] ERROR: Transaction Failed. Recipients unique ID does not exist.\n");
            break;
        case TXN_ERR_SELF_TRANSFER:
            printf("[!] ERROR: Operation Denied. Cannot transfer funds to your own account.\n");
            break;
        default:
            printf("[!] ERROR: Someting wrong has occured.\n");
            break;
    }
}

void file_operation_error(FileStatus status) {
    switch (status) {
        case FILE_WRITE_FAILED: perror("[!] ERROR: Cannot write into the file.\n"); break;
        case FILE_CORRUPTED: perror("[!] ERROR: File is corrupted.\n"); break;
        case FILE_PERMISSION_DENIED: perror("[!] ERROR: System doesn't have administration rights to the folder.\n"); break;
        case FILE_NOT_FOUND:
        default: break;
    }
}

void invalid_pin_length() {
    printf("[!] ERROR: Invalid PIN length.\n");
}

void invalid_selection_msg() {
    printf("[!] ERROR: Invalid selection.\n");
}