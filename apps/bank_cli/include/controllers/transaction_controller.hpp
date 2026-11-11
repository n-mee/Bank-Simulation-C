#pragma once
// Dependency Headers
#include "domain/account_model.hpp"
#include "account_repository.hpp"

/**
 * @brief handles the transaction menu and switches dynamically depending on transaction type
 * @param db pointer reference to the active database used to look for receiver in transfer
 * @param current_user reference for the current active account
 * @param type transaction flag used for dynamic switching operation
 */
void handle_transaction_pipeline(BankDatabase* db, Account* current_user, TransactionType type);