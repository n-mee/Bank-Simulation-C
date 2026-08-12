#include <stdio.h>
#include <stdbool.h>
#include "common/file_utility.h"
#include "models/account_model.h"
#include "services/transaction_service.h"

TransactionStatus execute_withdraw(Account* current_user, long long amount) {
    if (!current_user) return TXN_ERR_NULL;

    if (amount <= 0) return TXN_INVALID_BAL;
    if (current_user->bal < amount) return TXN_INSUFFICIENT_BAL;

    write_transac_log("PENDING", "WITHDRAW", current_user->accID, 0, amount);

    current_user->bal -= amount;

    write_transac_log("COMMIT", "WITHDRAW", current_user->accID, 0, amount);
    return TXN_OPERATION_SUCCESS;
}

TransactionStatus execute_deposit(Account* current_user, long long amount) {
    if (!current_user) return TXN_ERR_NULL;

    if (amount <= 0) return TXN_INVALID_BAL;

    if (current_user->bal > 9223372036854775807LL - amount) return TXN_BAL_OVERFLOW;

    write_transac_log("PENDING", "DEPOSIT", 0, current_user->accID, amount);

    current_user->bal += amount;

    write_transac_log("COMMIT", "DEPOSIT", 0, current_user->accID, amount);
    return TXN_OPERATION_SUCCESS;
}

TransactionStatus execute_transfer(Account* sender, Account* receiver, long long amount) {
    if (!sender || !receiver) return TXN_ERR_NULL;
    if (amount <= 0) return TXN_INVALID_BAL;
    if (sender->bal < amount) return TXN_INSUFFICIENT_BAL;
    if (receiver->bal > 9223372036854775807LL - amount) return TXN_BAL_OVERFLOW;

    write_transac_log("PENDING", "TRANSFER", sender->accID, receiver->accID, amount);

    sender->bal -= amount;
    receiver->bal += amount;

    write_transac_log("COMMIT", "TRANSFER", sender->accID, receiver->accID, amount);
    return TXN_OPERATION_SUCCESS;
}