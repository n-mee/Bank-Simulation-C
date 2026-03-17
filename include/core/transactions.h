#ifndef MENU_FUNC_H
#define MENU_FUNC_H

#include <stdbool.h>
#include "data/static_user.h"
bool execute_withdraw(User* current_user, double withdraw_amt);
bool execute_deposit(User* current_user, double deposit_amt);
bool execute_transfer(User* sender, User* receiver, double transfer_amt);

#endif