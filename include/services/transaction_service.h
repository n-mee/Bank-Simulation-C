#ifndef TRANSACTION_SERVICE_H
#define TRANSACTION_SERVICE_H

// Dependency Headers
#include "common/exit_status.h"
#include "models/account_model.h"

TransactionStatus execute_withdraw(Account* current_user, long long amount);
TransactionStatus execute_deposit(Account* current_user, long long amount);
TransactionStatus execute_transfer(Account* sender, Account* receiver, long long amount);

#endif