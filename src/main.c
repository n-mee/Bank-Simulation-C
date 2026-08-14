#include <stdio.h>
#include <stdbool.h>
#include "cli/display_success_msg.h"
#include "cli/display_error_msg.h"
#include "controllers/auth_controller.h"
#include "cli/input.h"
#include "common/file_operations.h"
#include "repositories/account_repository.h"
#include "common/exit_status.h"
#include "cli/menus.h"
#include "cli/displays.h"
#include "controllers/account_controller.h"
#include "controllers/transaction_controller.h"

int main(void) {

    BankDatabase bank;
    if (db_init(&bank, 4) == 0) {
        return 1;
    }

    FileStatus status;
    status = load_from_file(&bank);

    if (status == FILE_OK) {
        file_operation_success(status);
    } else if (status == FILE_NOT_FOUND) {
        printf("[-] WARN: No exiting database found. Starting a fresh save.\n");
    } else {
        file_operation_error(status);
        db_termination(&bank);
        return 1;
    }

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
                    show_system_msg(MSG_EXIT_SYS);
                    current_session = NULL;
                    running = false;
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
    } else {
        file_operation_error(status);
    }

    db_termination(&bank);
    return 0;
}