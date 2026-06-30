#ifndef AUTH_CONTROLLER_H
#define AUTH_CONTROLLER_H

// initial headers
#include <stdbool.h>
#include "../include/data/database_functions.h"

void handle_registration(BankDatabase *db);
void handle_login(BankDatabase *db, Account **session_user);

#endif