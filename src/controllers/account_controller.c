/*  ACCOUNT SETTINGS MODULES
    
    What it does:
        1. specifically handles the account settings manu as well as the option inside
        2. only for specific account settings option
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "models/account_model.h"
#include "cli/menus.h"
#include "cli/displays.h"
#include "common/validators.h"
#include "common/value_parser.h"
#include "cli/input.h"
#include "services/account_service.h"
#include "controllers/account_controller.h"


// changes the pin of the user using Pass-by-referrence
void change_pin_pipeline(Account *session) {
    char new_pin[PIN_LENGTH];
    char current_pin[PIN_LENGTH];

    if (!get_prompt_string("\nEnter Current PIN: ", current_pin, PIN_LENGTH)) return;
    if (!is_valid_pin(session->profile.pin, current_pin)) return;
    // declaring var for new pin
    if (!get_prompt_string("\nEnter your New PIN: ", new_pin, PIN_LENGTH)) return;
    account_update_pin(session, new_pin);
    // return pin success
    change_pin_success(session);
}

// change name function using Pass-by-referrence
void change_username_pipeline(Account *session) {
    char current_pin[PIN_LENGTH];
    char new_name[50];

    if (!get_prompt_string("\nEnter current PIN: ", current_pin, PIN_LENGTH)) return;
    if (!is_valid_pin(session->profile.pin, current_pin)) return;

    // declaring of variable for new name
    if (!get_prompt_string("\nEnter your new Display Name: ", new_name, PIN_LENGTH)) return;
    if (!is_valid_length_input(new_name)) return;

    // same logic in pin, changes the account name and returns the success msg
    account_update_username(session, new_name);
    change_name_success(session);
}

void change_email_pipeline(Account *session) {
    char current_pin[PIN_LENGTH];
    char new_email[51];

    if (!get_prompt_string("Enter your PIN: ", current_pin, PIN_LENGTH)) return;
    if(!is_valid_pin(session->profile.pin, current_pin)) return;

    if (!get_prompt_string("\nEnter your new email: ", new_email, PIN_LENGTH)) return;
    if (!is_valid_length_input(new_email)) return;

    account_update_email(session, new_email);
    update_email_status(session);
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

    bool in_settings = true;
    while (in_settings) {
        profile_settings();
        int choice = get_prompt_int("\nEnter your choice: ");

        switch(choice) {
            case 1:
                change_username_pipeline(current_session);
                break;
            case 2:
                change_email_pipeline(current_session);
                break;
            case 3:
                change_pin_pipeline(current_session);
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

 void update_daily_limit(Account *current_session) {
    bool choice;

    get_yn_prompt("\nDaily Limits should only be around 10,000 to 50,000.\nAre you sure you wanna continue? (yes/no): ", &choice);
    if (choice != true) {
        back_to_menu();
        return;
    }

    double new_limit = get_prompt_double("\nEnter new limit: ");
    set_daily_limit(current_session, new_limit);
}