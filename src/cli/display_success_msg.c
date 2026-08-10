#include <stdbool.h>
#include "cli/display_success_msg.h"

void account_operation_success(AccountOperationType type) {
    switch (type) {
        case UPDATE_PIN: printf("\nSuccessfully updated your PIN!\n"); break;
        case UPDATE_EMAIL: printf("\nSuccessfully updated your email!\n"); break;
        case UPDATE_USERNAME: printf("\nSuccessfully updated your username!\n"); break;
        default: break;
    }
}