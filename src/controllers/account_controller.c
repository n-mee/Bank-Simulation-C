/*  ACCOUNT SETTINGS MODULES
    
    What it does:
        1. specifically handles the account settings manu as well as the option inside
        2. only for specific account settings option
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cli/input.h"
#include "cli/menus.h"
#include "cli/displays.h"
#include "common/constants.h"
#include "common/validators.h"
#include "common/value_parser.h"
#include "common/system_logger.h"
#include "models/account_model.h"
#include "cli/display_error_msg.h"
#include "cli/display_success_msg.h"
#include "services/account_service.h"
#include "controllers/account_controller.h"

static void account_credentials_routing(AccountOperationType type, Credentials status) {

    SysLogLevel level = (status == CRED_ERR_INVALID_PIN) ? WARN :
                        (status == CRED_ERR_MISMATCH_PIN) ? WARN :
                        (status == CRED_OPERATION_SUCCESS) ? INFO : ERROR;
    
    log_system_operations(level, COMP_ACC_CREDS, status);

    if (status == CRED_OPERATION_SUCCESS) {
        account_operation_success(type);
    } else {
        account_operation_error(status);
    }

}

static void account_notifications_routing(AccountNotificationsType type, NotificationsStatus status) {

    SysLogLevel level = (status == NOTIF_WARN_ALREADY_SET) ? WARN :
                        (status == NOTIF_ERR_SESSION_NULL) ? ERROR : INFO;

    log_system_operations(level, COMP_ACC_NOTIF, status);

    if (status == NOTIF_WARN_ALREADY_SET || status == NOTIF_ERR_SESSION_NULL) {

        account_notification_fail(status);
    } else {
        account_notification_status(type, status);
    }

}

static void account_status_routing(AccountStateOperationType type, AccountStateStatus status) {

    SysLogLevel level = (status == STATUS_OPERATION_WARN_ALREADY_SET) ? WARN :
                        (status == STATUS_OPERATION_SUCCESS) ? INFO : ERROR;

    log_system_operations(level, COMP_ACC_STATUS, status);

    if (status != STATUS_OPERATION_SUCCESS) {
        account_state_error(status);
    } else {
        account_state_success(type);
    }

}

// handles the users settings config if he presses option 4
void handle_account_settings(Account *current_session) {
    // set state for while loop
    bool in_settings = true;
    while (in_settings) {
        account_menu();
        int choice = get_prompt_int("\nEnter your choice: ");

        switch (choice) {
            case 1:
                handle_profile_settings(current_session);
                break;
            case 2:
                handle_preference_settings(current_session);
                break;
            case 3:
                handle_payment_settings(current_session);
                break;
            case 0:
                // if user presses 0 which is exit it closes immediately
                show_system_msg(MSG_EXIT_TO_MENU);
                in_settings = false;
                break;
            default:
                // prints an error msg and goes back to the menu
                invalid_selection_msg();
                break;
        }
    }
}

void handle_profile_settings(Account *current_session) {
    Credentials status;
    bool in_settings = true;

    while (in_settings) {
        profile_settings();
        int choice = get_prompt_int("\nEnter your choice: ");

        switch(choice) {
            case 1:
                status = change_credential_pipeline(current_session, UPDATE_USERNAME);
                account_credentials_routing(UPDATE_USERNAME, status);
                break;
            case 2:
                status = change_credential_pipeline(current_session, UPDATE_EMAIL);
                account_credentials_routing(UPDATE_EMAIL, status);
                break;
            case 3:
                status = change_credential_pipeline(current_session, UPDATE_PIN);
                account_credentials_routing(UPDATE_PIN, status);            
                break;
            case 0:
                show_system_msg(MSG_EXIT_TO_MENU);
                in_settings = false;
                break;
            default:
                invalid_selection_msg();
                continue;
        }
    }
}

void handle_preference_settings(Account *current_session) {
    NotificationsStatus status;
    bool toggle_choice;
    bool in_settings = true;

    while (in_settings) {
        preference_settings();
        int choice = get_prompt_int("\nEnter your choice: ");

        switch (choice) {
            case 1:
                if (get_yn_prompt("\nDo you wanna toggle email notifications? (yes/no): ", &toggle_choice)) {
                    status = account_notifications_pipeline(current_session, ENABLE_EMAIL_NOTIF, toggle_choice);
                    account_notifications_routing(ENABLE_EMAIL_NOTIF, status);
                }
                break;
            case 2:
                if (get_yn_prompt("\nDo you wanna toggle push notifications? (yes/no): ", &toggle_choice)) {
                    status = account_notifications_pipeline(current_session, ENABLE_PUSH_NOTIF, toggle_choice);
                    account_notifications_routing(ENABLE_PUSH_NOTIF, status);
                }
                break;
            case 3:
                handle_sub_pref_settings(current_session);
                break;
            case 0:
                show_system_msg(MSG_EXIT_TO_MENU);
                in_settings = false;
                break;
            default:
                invalid_selection_msg();
                break;
        }
    }
}

void handle_sub_pref_settings(Account *current_session) {
    NotificationsStatus status;
    bool toggle_choice;
    bool in_subpref = true;

    while (in_subpref) {
        alert_pref_settings();
        int choice = get_prompt_int("\nEnter your choice: ");

        switch (choice) {
            case 1:
                if (get_yn_prompt("\nDo you wanna toggle Large Transaction Alerts? (yes/no): ", &toggle_choice)) {
                    status = account_notifications_pipeline(current_session, ENABLE_LARGE_TXN_NOTIF, toggle_choice);
                    account_notifications_routing(ENABLE_LARGE_TXN_NOTIF, status);
                }
                break;
            case 2:
                if (get_yn_prompt("\nDo you wanna toggle Low Balance Alerts? (yes/no): ", &toggle_choice)) {
                    status = account_notifications_pipeline(current_session, ENABLE_LOW_BAL_NOTIF, toggle_choice);
                    account_notifications_routing(ENABLE_LOW_BAL_NOTIF, status);
                }
                break;
            case 0:
                show_system_msg(MSG_EXIT_TO_MENU);
                in_subpref = false;
                break;
            default:
                invalid_selection_msg();
                break;
        }
    }
}


void handle_payment_settings (Account *current_session) {
    AccountStateStatus status;
    bool in_settings = true;
    bool in_sub_settings = false;

    while (in_settings) {

        if (in_sub_settings) {
            account_status_menu();
        } else {
            payment_settings();
        }

        int choice = get_prompt_int("\nEnter your choice: ");

        if (!in_sub_settings) {
            switch (choice) {
                case 1:
                    in_sub_settings = true;
                    break;
                case 2:
                    status = account_status_pipeline(current_session, SET_LIMIT_UPDATE);
                    account_status_routing(SET_LIMIT_UPDATE, status);
                    break;
                case 0:
                    show_system_msg(MSG_EXIT_TO_MENU);
                    in_settings = false;
                    break;
                default:
                    invalid_selection_msg();
                    break;
            }
        } else {
            switch (choice) {
                case 1:
                    status = account_status_pipeline(current_session, SET_STATE_FREEZE);
                    account_status_routing(SET_STATE_FREEZE, status);
                    break;
                case 2:
                    status = account_status_pipeline(current_session, SET_STATE_ACTIVATE);
                    account_status_routing(SET_STATE_ACTIVATE, status);
                    break;
                case 3:
                    status = account_status_pipeline(current_session, SET_STATE_CLOSED);
                    account_status_routing(SET_STATE_CLOSED, status);
                    break;
                case 0:
                    in_sub_settings = false;
                    break;
                default:
                    invalid_selection_msg();
                    break;
            }
        }
    }
}