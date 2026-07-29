#ifndef ACCOUNT_ACTIONS_H
#define ACCOUNT_ACTIONS_H

// dependency header (data model)
#include "../include/data/model.h"
#include "../include/data/database_functions.h"

/** ================================
 *        ACCOUNT FUNCTIONS
 * ================================= 
 * 
 * @note: 
 *      This is the core logic of changing
 *      account credentials, no other logic
 *      besides replacing values is written
 *      in this codebase
*/

/**
 * @brief Changes the pin with the new one
 * @param session Current account struct used to change the values inside
 * @param new_pin New PIN value to replace the old one
 */
void account_update_pin(Account *session, const char* new_pin);

/**
 * @brief Changes the current display name to a new one
 * @param session Current account struct used to change the values inside
 * @param new_name New display name value to replace the old one
 */
void account_update_username(Account *session, const char* new_name);

void account_update_email(Account *session, const char* new_email);

#endif