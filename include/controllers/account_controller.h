#ifndef ACCOUNT_CONTROLLER_H
#define ACCOUNT_CONTROLLER_H

// Dependency Headers
#include "models/account_model.h"

/**
 * @brief Account settings menu logic switching
 * @param current_session Pointer reference to account in database
 */
void handle_account_settings(Account *current_session);

void handle_profile_settings(Account *current_session);
void handle_preference_settings(Account *current_session);
void handle_sub_pref_settings(Account *current_session);
void handle_payment_settings(Account *current_session);

#endif