#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "cli/displays.h"
#include "cli/input.h"
#include "common/value_parser.h"
#include "controllers/auth_controller.h"
#include "repositories/account_repository.h"

// handles the gateway registartion logic
void handle_registration(BankDatabase *db) {
    Account temp_acc = {0};

    get_string_prompt("Enter your Full Government Name: ", temp_acc.profile.name, sizeof(temp_acc.profile.name));
    get_string_prompt("Enter your Username: ", temp_acc.profile.username, sizeof(temp_acc.profile.username));
    get_string_prompt("Enter your email: ", temp_acc.profile.email, sizeof(temp_acc.profile.email));
    get_string_prompt("Enter your PIN: ", temp_acc.profile.pin, sizeof(temp_acc.profile.pin));

    temp_acc.preference.email_notif = false;
    temp_acc.preference.push_notif = false;
    temp_acc.preference.low_balance_alert = false;
    temp_acc.preference.large_transaction_alert = false;
    temp_acc.controls.status = ACCOUNT_ACTIVE;
    temp_acc.controls.daily_limit = 50000.00;

    // creates an account using another module function in database and returns a value as ID
    int acc_id = db_account_creation(db, temp_acc);

    // checks if the id is not negative one
    if (acc_id == -1) {
        memory_allocation_error();
        return;
    }
    // if the id pass the validator it proceeds here to print your new acc
    registration_success(&acc_id);
}

// handles the gateway login menu logic
void handle_login(BankDatabase *db, Account **session_user) {
    char temp_pin[6];
    int temp_id = get_prompt_int("Enter your Unique ID: ");

    // uses a custom-made search algorithm to search for matching IDs
    int search_id = db_find_identity(db, temp_id);
    /*  
        if the algorithm fails and returns negative one 
        the code below prints a msg sets the account 
        to empty and closes the function
    */
    if (search_id == -1){
        invalid_search();
        *session_user = NULL;
        return;       
    }

    if (db->records[search_id].controls.status == ACCOUNT_CLOSED) {
        acc_closed();
        return;
    }

    // prompts a pin input and checks if the pin input matches the one in account
    get_string_prompt("Enter your PIN: ", temp_pin, sizeof(temp_pin));
    // if it's not the code below exits the function
    if (strcmp(temp_pin, db->records[search_id].profile.pin) != 0){
        wrong_pin_msg();
        *session_user = NULL;
        return;
    }

    // if it succeeds it should proceed on using the existing account as the current account session
    *session_user = &db->records[search_id];
    login_successful();
}