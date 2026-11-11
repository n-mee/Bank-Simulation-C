#pragma once

// Dependency Headers
#include "account_repository.hpp"

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