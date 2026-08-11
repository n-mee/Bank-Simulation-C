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
        case ERR_INVALID_DOUBLE: printf("[!] ERROR: Input does not start with a decimal.\n"); break;
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

void invalid_pin_length() {
    printf("[!] ERROR: Invalid PIN length.\n");
}