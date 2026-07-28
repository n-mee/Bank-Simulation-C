/*  ACCOUNT SETTINGS MODULES
    
    What it does:
        1. specifically handles the account settings manu as well as the option inside
        2. only for specific account settings option
*/
#include <stdbool.h>
#include "../include/data/model.h"
#include "../include/views/menus.h"
#include "../include/views/displays.h"
#include "../include/utils/validators.h"
#include "../include/utils/input_parser.h"
#include "../include/core/account_actions.h"
#include "../include/controllers/account_controller.h"


// changes the pin of the user using Pass-by-referrence
void change_pin_pipeline(Account *session) {
    char current_pin[6];
    get_string_prompt("\nEnter Current PIN: ", current_pin, sizeof(current_pin));

    // check if the current pin matches before changing it
    if (!is_valid_pin(session->pin, current_pin)) return;

    // declaring var for new pin
    char new_pin[6];
    get_string_prompt("\nEnter your New PIN: ", new_pin, sizeof(new_pin));

    // change pin logic
    account_update_pin(session, new_pin);
    // return pin success
    change_pin_success(session);
}

// change name function using Pass-by-referrence
void change_name_pipeline(Account *session) {
    char current_pin[6];
    get_string_prompt("\nEnter current PIN: ", current_pin, sizeof(current_pin));

    // checks if the current pin inputted matches the current_user's pin
    if (!is_valid_pin(session->pin, current_pin)) return;

    // declaring of variable for new name
    char new_name[50];
    get_string_prompt("\nEnter your new Display Name: ", new_name, sizeof(new_name));

    // checks if the length of the name meets the require length for input (e.g. is it more than 50 or less than 4)
    if (!is_valid_length_input(new_name)) return;

    // same logic in pin, changes the account name and returns the success msg
    account_update_name(session, new_name);
    change_name_success(session);
}

// handles the users settings config if he presses option 4
void handle_account_settings(Account *current_session) {
    // set state for while loop
    bool in_settings = true;
    while (in_settings) {
        account_menu();
        int choice = get_int_prompt("\nEnter your choice: ");

        switch (choice) {
            case 1:
                // logic for changing name function can be seen above
                change_name_pipeline(current_session);
                break;
            case 2:
                // same goes here but for pin
                change_pin_pipeline(current_session);
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