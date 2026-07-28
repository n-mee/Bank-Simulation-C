#ifndef TRANSACTION_CONTROLLER_H
#define TRANSACTION_CONTROLLER_H

// Dependency Headers
#include "data/model.h"
#include "data/database_functions.h"

/**
 * @brief Processes account withdrawal after several safety checks
 * @param current_user Pointer to current active user
 */
void handle_withdraw_request(Account* current_user);

/**
 * @brief Handles account logic with several security checks
 * @param current_user Pointer to current active user
 */
void handle_deposit_request(Account* current_user);

/**
 * @brief Processing account transfer between 2 accounts after several security checks
 * @param db Pointer to master database for account reference
 * @param sender Pointer to current active user who's the sender
 */
void handle_transfer_request(BankDatabase *db, Account *sender);

#endif