#ifndef AUTH_CONTROLLER_H
#define AUTH_CONTROLLER_H

#include "../include/data/database_manager.h"

void handle_registration(BankDatabase *db);
void handle_login(BankDatabase *db, Account **session_user);
//void handle_logout();

#endif