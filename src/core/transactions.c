#include <stdio.h>
#include <stdbool.h>
#include "data/static_user.h"
#include "core/transactions.h"
#include "auth/auth.h"

bool execute_withdraw(User* current_user, double withdraw_amt) {
    // Checks the account balance.
    if (current_user->bal < withdraw_amt) return false;

    // Checks if the amt is sufficient
    if (withdraw_amt <= 0) return false;

    // Execute the withdrawal method.
    current_user->bal -= withdraw_amt;
    return true;
}

bool execute_deposit(User* current_user, double deposit_amt) {
    // Checks if the amt is sufficient
    if (deposit_amt <= 0) return false;

    //Executes the deposit logic
    current_user->bal += deposit_amt;
    return true;
}

bool execute_transfer(User* sender, User* receiver, double transfer_amt) {
    // Checks the sender's balance for sufficiency
    if (sender->bal < transfer_amt) return false;

    // Checks if the amt is sufficent
    if (transfer_amt <= 0) return false;

    // Executes the transfer method.
    sender->bal -= transfer_amt;
    receiver->bal += transfer_amt;
    return true;
}