#ifndef ACCOUNT_CONTROLLER_H
#define ACCOUNT_CONTROLLER_H

// Dependency Headers
#include "../include/data/model.h"

/**
 * @brief Handles the process of changing account pin
 * @param session Pointer reference for account data to be altered
 */
void change_pin_pipeline(Account *session);

/**
 * @brief Handles the process of changing account name
 * @param session Pointer reference for account data alterting
 */
void change_name_pipeline(Account *session);

/**
 * @brief Account settings menu logic switching
 * @param current_session Pointer reference to account in database
 */
void handle_account_settings(Account *current_session);

#endif