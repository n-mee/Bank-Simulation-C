#ifndef AUTH_CONTROLLER_H
#define AUTH_CONTROLLER_H

// Dependency Headers
#include <stdbool.h>
#include "../include/data/database_functions.h"

/**
 * @brief Handles identity registration menu logic
 * @param db Main database used to alter account datas
 */
void handle_registration(BankDatabase *db);
/**
 * @brief Handles the login portal of identity portal
 * @param db Main database used to access accounts
 * @param session_user Current active account found in database
 */
void handle_login(BankDatabase *db, Account **session_user);

#endif