#include <stdio.h>
#include <stdbool.h>
#include "controllers/auth_controller.h"
#include "utils/input_parser.h"
#include "data/database_manager.h"
#include "views/menus.h"
#include "views/displays.h"
#include "controllers/transaction_controller.h"

int main(void) {

    BankDatabase bank;
    db_init(&bank, 4);

    Account *current_session = NULL;
    bool running = true;
    int choice;

    while(running) {
        if (current_session == NULL){
            gateway_menu();
            choice = get_int_prompt("Enter your choice: ");

            switch (choice) {
                case 1:
                    handle_login(&bank, &current_session);
                    break;
                case 2:
                    handle_registration(&bank);
                    break;
                case 0:
                    running = false;
                    break;
                default:
                    invalid_selection_msg();
                    break;
            }
        } else {
            main_menu();
            choice = get_int_prompt("Enter your choice: ");

            switch (choice) {
                case 1:
                    handle_withdraw_request(current_session);
                    break;
                case 2:
                    handle_deposit_request(current_session);
                    break;
                case 3:
                    handle_transfer_request(&bank, current_session);
                    break;
                case 4:
                    wip_msg();
                    running = false;
                    break;
                case 0:
                    exit_msg();
                    current_session = NULL;
                    break;
                default:
                    invalid_selection_msg();
                    break;
            }
        }
    }

    db_termination(&bank);
    return 0;
}