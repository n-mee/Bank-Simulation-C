#ifndef TRANSACTION_SERVICE_H
#define TRANSACTION_SERVICE_H

// Dependency Headers
#include "common/exit_status.h"
#include "models/account_model.h"

/**
 * @brief handles the withdraw operation
 * @param current_user reference for current active user
 * @param amount balance reference used for transaction operation
 * @return a custom enum code for errors and success msg
 */
TransactionStatus execute_withdraw(Account* current_user, long long amount);

/**
 * @brief handles the deposit operation
 * @param current_user reference for current active user
 * @param amount balance ref used for transaction operation
 * @return a custom enum code for errors and success msg
 */
TransactionStatus execute_deposit(Account* current_user, long long amount);

/**
 * @brief handles transfer operation and logs them using WAL logger
 * @param sender account reference for the sender (current active user)
 * @param receiver account reference for the receiver (account target found in db)
 * @param amount balance ref used for transfer transaction operation
 * @return a custom enum code for errors and success msg
 */
TransactionStatus execute_transfer(Account* sender, Account* receiver, long long amount);

#endif