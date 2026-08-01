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
void change_username_pipeline(Account *session);

void change_email_pipeline(Account *session);

/**
 * @brief Account settings menu logic switching
 * @param current_session Pointer reference to account in database
 */
void handle_account_settings(Account *current_session);

void handle_profile_settings(Account *current_session);
void handle_preference_settings(Account *current_session);
void handle_sub_pref_settings(Account *current_session);
void handle_payment_settings(Account *current_session);
void update_daily_limit(Account *current_session);

#endif