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
#include "services/account_service.h"
#include "controllers/account_controller.h"

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
    bool c;
    bool in_settings = true;

    while (in_settings) {
        preference_settings();
        int choice = get_prompt_int("\nEnter your choice: ");

        switch (choice) {
            case 1:
                get_yn_prompt("\nDo you wanna toggle email notifications? (yes/no): ", &c);
                set_email_notif(current_session, c);
                break;
            case 2:
                get_yn_prompt("\nDo you wanna toggle push notifications? (yes/no): ", &c);
                set_push_notif(current_session, c);
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
                continue;
        }
    }
}

void handle_sub_pref_settings(Account *current_session) {
    bool c;
    bool in_subpref = true;

    while (in_subpref) {
        alert_pref_settings();
        int choice = get_prompt_int("\nEnter your choice: ");

        switch (choice) {
            case 1:
                get_yn_prompt("\nDo you wanna toggle Low Balance Alerts? (yes/no): ", &c);
                set_low_bal_notif(current_session, c);
                break;
            case 2:
                get_yn_prompt("\nDo you wanna toggle Large Transaction Alerts? (yes/no): ", &c);
                set_large_txn_notif(current_session, c);
                break;
            case 0:
                back_to_menu();
                in_subpref = false;
                break;
            default:
                invalid_selection_msg();
                continue;
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