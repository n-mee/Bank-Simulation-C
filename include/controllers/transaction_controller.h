#ifndef TRANSACTION_CONTROLLER_H
#define TRANSACTION_CONTROLLER_H

// Dependency Headers
#include "models/account_model.h"
#include "repositories/account_repository.h"

/**
 * @brief handles the transaction menu and switches dynamically depending on transaction type
 * @param db pointer reference to the active database used to look for receiver in transfer
 * @param current_user reference for the current active account
 * @param type transaction flag used for dynamic switching operation
 */
void handle_transaction_pipeline(BankDatabase* db, Account* current_user, TransactionType type);

#endif