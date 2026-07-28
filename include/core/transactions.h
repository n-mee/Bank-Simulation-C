#ifndef TRANSACTION_H
#define TRANSACTION_H

// Dependency Headers
#include <stdbool.h>
#include "../include/data/model.h"

/**
    ======================================
            TRANSACTION FUNCTIONS
    =====================================

 * TODO:
 *      Improve transaction logics and add more guardrails and proper
 *      error handling.
 * 
 * @note: This code was written "BEFORE" database was implemented so 
 *        it lacks security and more flexible logic
*/


/**
 * @brief Executes withdraw method by deducting account balance on input amount
 * @param current_user Account pointer for accessing account balance
 * @param withdraw_amt Input amount for balance to be deducted
 * @return True if code successfuly deducted balance, False if any error occurs during runtime checking
 */
bool execute_withdraw(Account* current_user, double withdraw_amt);

/**
 * @brief Executes deposit via adding balance based on input amount
 * @param current_user Account pointer for accessing account balance
 * @param deposit_amt Input amount for balance to be incremented
 * @return True if logic successfuly executed, False if it fails verification
 */
bool execute_deposit(Account* current_user, double deposit_amt);

/**
 * @brief Increments and Decrements 2 account balance based on transfer amount
 * @param sender Current session account to dispatch balance to recipent
 * @param receiver Account recipent in the process of receiving the money
 * @param transfer_amt Amount of money to be change values of 2 accounts
 * @return True if transfer logic is successful, False if it fails balance verification
 */
bool execute_transfer(Account* sender, Account* receiver, double transfer_amt);

#endif