#include <stdbool.h>
#include "../include/data/model.h"
#include "../include/views/menus.h"
#include "../include/views/displays.h"
#include "../include/utils/validators.h"
#include "../include/utils/input_parser.h"
#include "../include/core/account_actions.h"
#include "../include/controllers/account_controller.h"

void change_pin_pipeline(Account *session) {
    char current_pin[6];
    get_string_prompt("\nEnter Current PIN: ", current_pin, sizeof(current_pin));

    if (!is_valid_pin(session->pin, current_pin)) return;

    char new_pin[6];
    get_string_prompt("\nEnter your New PIN: ", new_pin, sizeof(new_pin));

    account_update_pin(session, new_pin);
    change_pin_success(session);
}

void change_name_pipeline(Account *session) {
    char current_pin[6];
    get_string_prompt("\nEnter current PIN: ", current_pin, sizeof(current_pin));

    if (!is_valid_pin(session->pin, current_pin)) return;

    char new_name[50];
    get_string_prompt("\nEnter your new Display Name: ", new_name, sizeof(new_name));

    if (!is_valid_length_input(new_name)) return;

    account_update_name(session, new_name);
    change_name_success(session);
}


void handle_account_settings(Account *current_session) {
    bool in_settings = true;
    while (in_settings) {
        account_menu();
        int choice = get_int_prompt("\nEnter your choice: ");

        switch (choice) {
            case 1:
                change_name_pipeline(current_session);
                break;
            case 2:
                change_pin_pipeline(current_session);
                break;
            case 0:
                back_to_menu();
                in_settings = false;
                break;
            default:
                break;
        }
    }
}