#ifndef TRANSACTION_CONTROLLER_H
#define TRANSACTION_CONTROLLER_H

// Transact Handlers
#include "data/model.h"
#include "data/database_functions.h"
void handle_withdraw_request(Account* current_user);
void handle_deposit_request(Account* current_user);
void handle_transfer_request(BankDatabase *db, Account *sender);

//Input Handler
#endif