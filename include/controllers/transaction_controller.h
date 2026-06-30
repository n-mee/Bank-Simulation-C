#ifndef TRANSACTION_CONTROLLER_H
#define TRANSACTION_CONTROLLER_H

// Dependency Headers
#include "data/model.h"
#include "data/database_functions.h"

// fuction declarations
void handle_withdraw_request(Account* current_user);
void handle_deposit_request(Account* current_user);
void handle_transfer_request(BankDatabase *db, Account *sender);

#endif