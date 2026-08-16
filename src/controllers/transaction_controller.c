#include "common/system_logger.h"
#include "repositories/account_repository.h"
#include "models/account_model.h"
#include "cli/display_success_msg.h"
#include "cli/display_error_msg.h"
#include "services/transaction_service.h"
#include "controllers/transaction_controller.h"
#include "common/constants.h"
#include "common/validators.h"
#include "cli/input.h"

static void account_transaction_routing(TransactionType type, TransactionStatus status) {
    if (status == TXN_OPERATION_SUCCESS) {
        account_transaction_success(type);
        wait_for_delay(3);
        clear_screen();
    } else {
        account_transaction_fail(status);
        wait_for_delay(3);
        clear_screen();
    }
}

void handle_transaction_pipeline(BankDatabase* db, Account* current_user, TransactionType type) {
    if (!current_user) {
        log_system_operations(ERROR, COMP_TRANSACTION, TXN_ERR_NULL);
        return;
    }

    char PIN[PIN_LENGTH + 1];
    if (!get_prompt_string("Enter your PIN: ", PIN, sizeof(PIN))) {
        account_transaction_routing(type, TXN_INVALID_PIN);
        return;
    }
    if (!is_valid_pin(current_user->profile.pin, PIN)) {
        account_transaction_routing(type, TXN_MISMATCH_PIN);
        return;
    }

    Account* receiver = NULL;

    if (type == TRANSFER) {
        if (!db) return;
        int r_id = get_prompt_int("Enter receiver's UID: ");
        int id_found = db_find_identity(db, r_id);

        if (id_found == -1) {
            account_transaction_routing(type, TXN_ERR_RECEIVER_NOT_FOUND);
            return;
        }
        if (db->records[id_found].accID == current_user->accID) {
            account_transaction_routing(type, TXN_ERR_SELF_TRANSFER);
            return;
        }

        receiver = &db->records[id_found];
    }

    long long amount = get_prompt_amount("Enter amount: ");

    TransactionStatus result;
    if (type == DEPOSIT) result = execute_deposit(current_user, amount);
    else if (type == WITHDRAW) result = execute_withdraw(current_user, amount);
    else if (type == TRANSFER) result = execute_transfer(current_user, receiver, amount);
    else return;

    if (result == TXN_OPERATION_SUCCESS) {
        log_system_operations(INFO, COMP_TRANSACTION, result);
    } else {
        log_system_operations(WARN, COMP_TRANSACTION, result);
    }

    account_transaction_routing(type, result);
}