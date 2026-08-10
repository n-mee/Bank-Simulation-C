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
#include "models/account_model.h"
#include "cli/display_error_msg.h"
#include "cli/display_success_msg.h"
#include "services/account_service.h"
#include "controllers/account_controller.h"

static void account_notifications_routing(AccountNotificationsType type, NotificationsStatus status) {
    if (status == NOTIF_WARN_ALREADY_SET || status == NOTIF_ERR_SESSION_NULL) {
        account_notification_fail(status);
    } else {
        account_notification_status(type, status);
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
                back_to_menu();
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
                account_operation_error(status);
                break;
            case 2:
                status = change_credential_pipeline(current_session, UPDATE_EMAIL);
                account_operation_error(status);
                break;
            case 3:
                status = change_credential_pipeline(current_session, UPDATE_PIN);
                account_operation_error(status);               
                break;
            case 0:
                back_to_menu();
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
                back_to_menu();
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
                back_to_menu();
                in_subpref = false;
                break;
            default:
                invalid_selection_msg();
                break;
        }
    }
}

void update_account_status(Account *current_session) {
    bool in_accstatus = true;
    while (in_accstatus) {
        account_status_menu();
        int choice = get_prompt_int("\nEnter your choice: ");

        switch (choice) {
            case 1:
                set_acc_frozen(current_session);
                break;
            case 2:
                set_acc_active(current_session);
                break;
            case 3:
                set_acc_closed(current_session);
                break;
            case 0:
                back_to_menu();
                in_accstatus = false;
                break;
            default:
                invalid_selection_msg();
                continue;
        }
    }
}

void handle_payment_settings(Account *current_session) {
    bool in_psettings = true;
    while (in_psettings) {
        payment_settings();
        int choice = get_prompt_int("\nEnter your choice: ");

        switch (choice) {
            case 1:
                update_account_status(current_session);
                break;
            case 2:
                update_daily_limit(current_session);
                break;
            case 0:
                back_to_menu();
                in_psettings = false;
                break;
            default:
                invalid_selection_msg();
                continue;
        }
    }
}