#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "cli/input.h"
#include "cli/displays.h"
#include "common/constants.h"
#include "common/validators.h"
#include "common/value_parser.h"
#include "cli/display_error_msg.h"
#include "services/auth_service.h"
#include "cli/display_success_msg.h"
#include "controllers/auth_controller.h"
#include "repositories/account_repository.h"

// handles the gateway registartion logic
void handle_registration(BankDatabase *db) {
    Account temp_acc = {0};

    if (!get_prompt_string("Enter your Full Government Name: ", temp_acc.profile.name, sizeof(temp_acc.profile.name)) ||
        !get_prompt_string("Enter your Username: ", temp_acc.profile.username, sizeof(temp_acc.profile.username)) ||
        !get_prompt_string("Enter your email: ", temp_acc.profile.email, sizeof(temp_acc.profile.email)) ||
        !get_prompt_string("Enter your PIN: ", temp_acc.profile.pin, sizeof(temp_acc.profile.pin))) {
        return;
    }

    // creates an account using another module function in database and returns a value as ID
    int acc_id = 0;
    AuthStatus status = register_account(db, temp_acc, &acc_id);

    if (status == AUTH_REGISTRATION_SUCCESS) {
        auth_operation_success(status, &acc_id, NULL);
    } else {
        auth_operation_error(status);
    }
}

// handles the gateway login menu logic
void handle_login(BankDatabase *db, Account **session_user) {
    char temp_pin[PIN_LENGTH + 1];
    int temp_id = get_prompt_int("Enter your Unique ID: ");

    // prompts a pin input and checks if the pin input matches the one in account
    if (!get_prompt_string("\nEnter your PIN: ", temp_pin, sizeof(temp_pin))) {
        *session_user = NULL;
        return;
    }

    AuthStatus status = authenticate_account(db, temp_id, temp_pin, session_user);

    if (status == AUTH_LOGIN_SUCCESS) {
        auth_operation_success(status, &temp_id, *session_user);
    } else {
        *session_user = NULL;
        auth_operation_error(status);
    }
}