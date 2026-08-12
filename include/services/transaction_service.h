#ifndef TRANSACTION_H
#define TRANSACTION_H

// Dependency Headers
#include <stdbool.h>
#include "common/exit_status.h"
#include "models/account_model.h"

TransactionStatus execute_withdraw(Account* current_user, long long amount);
TransactionStatus execute_deposit(Account* current_user, long long amount);
TransactionStatus execute_transfer(Account* sender, Account* receiver, long long amount);

#endif