#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "../include/views/displays.h"
#include "../include/utils/input_parser.h"
#include "../include/controllers/auth_controller.h"
#include "../include/data/database_functions.h"

// handles the gateway registartion logic
void handle_registration(BankDatabase *db) {
    char temp_name[50];
    char temp_pin[6];

    get_string_prompt("Enter your name: ", temp_name, sizeof(temp_name));
    get_string_prompt("Enter your PIN: ", temp_pin, sizeof(temp_pin));

    // creates an account using another module function in database and returns a value as ID
    int acc_id = db_account_creation(db, temp_name, temp_pin);

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
    int temp_id = get_int_prompt("Enter your Unique ID: ");

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