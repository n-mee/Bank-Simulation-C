#ifndef ACCOUNT_CONTROLLER_H
#define ACCOUNT_CONTROLLER_H

// Dependency Headers
#include "models/account_model.h"

/**
 * @brief Account settings menu logic switching
 * @param current_session Pointer reference to account in database
 */
void handle_account_settings(Account *current_session);

/**
 * @brief handles the account credentials menu
 * @param current_session reference for current active account
 */
void handle_profile_settings(Account *current_session);

/**
 * @brief handles the notifications preference settings
 * @param current_session reference for current active account
 */
void handle_preference_settings(Account *current_session);

/**
 * @brief handles the alert preference settings
 * @param current_session reference for current active account
 */
void handle_sub_pref_settings(Account *current_session);

/**
 * @brief handles account state and daily limit settings
 * @param reference for current active account
 */
void handle_payment_settings(Account *current_session);

#endif