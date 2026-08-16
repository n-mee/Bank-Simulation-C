#include <string.h>
#include <stdbool.h>
#include "cli/input.h"
#include "cli/menus.h"
#include "cli/displays.h"
#include "common/constants.h"
#include "common/validators.h"
#include "common/file_utility.h"
#include "common/system_logger.h"
#include "models/account_model.h"
#include "cli/display_error_msg.h"
#include "cli/display_success_msg.h"
#include "services/account_service.h"
#include "controllers/account_controller.h"

static void account_credentials_routing(AccountOperationType type, Credentials status) {

    SysLogLevel level = (status == CRED_ERR_INVALID_PIN) ? LOG_WARN :
                        (status == CRED_ERR_MISMATCH_PIN) ? LOG_WARN :
                        (status == CRED_OPERATION_SUCCESS) ? LOG_INFO : LOG_ERROR;
    
    log_system_operations(level, COMP_ACC_CREDS, status);

    if (status == CRED_OPERATION_SUCCESS) {
        account_operation_success(type);
        wait_for_delay(3);
        clear_screen();
    } else {
        account_operation_error(status);
        wait_for_delay(3);
        clear_screen();
    }

}

static void account_notifications_routing(AccountNotificationsType type, NotificationsStatus status) {

    SysLogLevel level = (status == NOTIF_WARN_ALREADY_SET) ? LOG_WARN :
                        (status == NOTIF_ERR_SESSION_NULL) ? LOG_ERROR : LOG_INFO;

    log_system_operations(level, COMP_ACC_NOTIF, status);

    if (status == NOTIF_WARN_ALREADY_SET || status == NOTIF_ERR_SESSION_NULL) {

        account_notification_fail(status);
        wait_for_delay(3);
        clear_screen();
    } else {
        account_notification_status(type, status);
        wait_for_delay(3);
        clear_screen();
    }

}

static void account_status_routing(AccountStateOperationType type, AccountStateStatus status) {

    SysLogLevel level = (status == STATUS_OPERATION_WARN_ALREADY_SET) ? LOG_WARN :
                        (status == STATUS_OPERATION_SUCCESS) ? LOG_INFO : LOG_ERROR;

    log_system_operations(level, COMP_ACC_STATUS, status);

    if (status != STATUS_OPERATION_SUCCESS) {
        account_state_error(status);
        wait_for_delay(3);
        clear_screen();
    } else {
        account_state_success(type);
        wait_for_delay(3);
        clear_screen();
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
                wait_for_delay(2);
                clear_screen();
                handle_profile_settings(current_session);
                break;
            case 2:
                wait_for_delay(2);
                clear_screen();
                handle_preference_settings(current_session);
                break;
            case 3:
                wait_for_delay(2);
                clear_screen();
                handle_payment_settings(current_session);
                break;
            case 0:
                // if user presses 0 which is exit it closes immediately
                show_system_msg(MSG_EXIT_TO_MENU);
                in_settings = false;
                wait_for_delay(1);
                clear_screen();
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
                wait_for_delay(1);
                clear_screen();
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
                wait_for_delay(1);
                clear_screen();
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
                wait_for_delay(1);
                clear_screen();
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
                    wait_for_delay(1);
                    clear_screen();
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
                    wait_for_delay(1);
                    clear_screen();
                    break;
                default:
                    invalid_selection_msg();
                    break;
            }
        }
    }
}