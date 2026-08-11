#include <stdio.h>
#include "cli/display_success_msg.h"

void account_operation_success(AccountOperationType type) {
    switch (type) {
        case UPDATE_PIN: printf("\nSuccessfully updated your PIN!\n"); break;
        case UPDATE_EMAIL: printf("\nSuccessfully updated your email!\n"); break;
        case UPDATE_USERNAME: printf("\nSuccessfully updated your username!\n"); break;
        default: break;
    }
}

void account_notification_status(AccountNotificationsType type, NotificationsStatus status) {
    const char* state_str = (status == NOTIF_SUCCESS_ENABLED) ? "ENABLED" : "DISABLED";

    switch (type) {
        case ENABLE_EMAIL_NOTIF: printf("Email notifications are now %s!\n", state_str); break;
        case ENABLE_PUSH_NOTIF: printf("Push notifications are now %s!\n", state_str); break;
        case ENABLE_LARGE_TXN_NOTIF: printf("Large Transaction alerts are now %s!\n", state_str); break;
        case ENABLE_LOW_BAL_NOTIF: printf("Low Balance alerts are now %s!\n", state_str); break;
        default: break;
    }
}

void account_state_success(AccountStateOperationType type) {
    switch (type) {
        case SET_STATE_FREEZE: printf("Successfully froze your account.\n"); break;
        case SET_STATE_ACTIVATE: printf("Successfully re-activate your account.\n"); break;
        case SET_STATE_CLOSED: printf("Successfully set your account as closed.\n"); break;
        case SET_LIMIT_UPDATE: printf("Successfully updated your account limits.\n"); break;
        default: break;
    }
}