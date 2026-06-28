#ifndef MENU_FUNC_H
#define MENU_FUNC_H

#include <stdbool.h>
#include "data/model.h"
bool execute_withdraw(Account* current_user, double withdraw_amt);
bool execute_deposit(Account* current_user, double deposit_amt);
bool execute_transfer(Account* sender, Account* receiver, double transfer_amt);

#endif