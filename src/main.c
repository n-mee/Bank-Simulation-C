#include <stdio.h>
#include <stdbool.h>
#include "controllers/auth_controller.h"
#include "cli/input.h"
#include "repositories/account_repository.h"
#include "common/exit_status.h"
#include "cli/menus.h"
#include "cli/displays.h"
#include "controllers/account_controller.h"
#include "controllers/transaction_controller.h"

int main(void) {

    BankDatabase bank;
    db_init(&bank, 4);

    db_load_from_file(&bank);

    Account *current_session = NULL;
    bool running = true;
    int choice;

    while(running) {
        if (current_session == NULL){
            gateway_menu();
            choice = get_prompt_int("Enter your choice: ");

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
            choice = get_prompt_int("Enter your choice: ");

            switch (choice) {
                case 1:
                    handle_transaction_pipeline(&bank, current_session, WITHDRAW);
                    break;
                case 2:
                    handle_transaction_pipeline(&bank, current_session, DEPOSIT);
                    break;
                case 3:
                    handle_transaction_pipeline(&bank, current_session, TRANSFER);
                    break;
                case 4:
                    handle_account_settings(current_session);
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

    db_save_to_file(&bank);
    db_termination(&bank);
    return 0;
}