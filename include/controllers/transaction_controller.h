#ifndef TRANSACTION_CONTROLLER_H
#define TRANSACTION_CONTROLLER_H

// Dependency Headers
#include "models/account_model.h"
#include "repositories/account_repository.h"

void handle_transaction_pipeline(BankDatabase* db, Account* current_user, TransactionType type);

#endif