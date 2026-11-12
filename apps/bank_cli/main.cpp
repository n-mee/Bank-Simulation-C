#include <stdio.h>
#include <stdbool.h>
#include "cli/display_success_msg.hpp"
#include "cli/display_error_msg.hpp"
#include "controllers/auth_controller.hpp"
#include "input.hpp"
#include "file_operations.hpp"
#include "account_repository.hpp"
#include "common/exit_status.hpp"
#include "cli/menus.hpp"
#include "cli/displays.hpp"
#include "controllers/account_controller.hpp"
#include "controllers/transaction_controller.hpp"

int main(void) {

    BankDatabase bank;
    if (db_init(&bank, 4) == 0) {
        return 1;
    }

    FileStatus status;
    status = load_from_file(&bank);

    if (status == FILE_OK) {
        file_operation_success(status);
        wait_for_delay(3);
        clear_screen();
    } else if (status == FILE_NOT_FOUND) {
        printf("[-] WARN: No exiting database found. Starting a fresh save.\n");
        wait_for_delay(3);
        clear_screen();
    } else {
        file_operation_error(status);
        wait_for_delay(3);
        clear_screen();
        db_termination(&bank);
        return 1;
    }

    Account *current_session = NULL;
    bool running = true;
    int choice;

    while(running) {
        if (current_session == NULL){
            Menu::TerminalGateway();
            choice = get_prompt_int("Enter your choice: ");

            switch (choice) {
                case 1:
                    handle_login(&bank, &current_session);
                    break;
                case 2:
                    handle_registration(&bank);
                    break;
                case 0:
                    wait_for_delay(3);
                    clear_screen();
                    running = false;
                    break;
                default:
                    invalid_selection_msg();
                    break;
            }
        } else {
            Menu::TerminalMain();
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
                    show_system_msg(MSG_EXIT_SYS);
                    current_session = NULL;
                    running = false;
                    wait_for_delay(3);
                    clear_screen();
                    break;
                default:
                    invalid_selection_msg();
                    break;
            }
        }
    }
    status = save_to_file(&bank);

    if (status == FILE_OK) {
        file_operation_success(status);
        wait_for_delay(3);
        clear_screen();
    } else {
        file_operation_error(status);
        wait_for_delay(3);
        clear_screen();
    }

    db_termination(&bank);
    return 0;
}