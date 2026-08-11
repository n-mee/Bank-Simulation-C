#ifndef ACCOUNT_ACTIONS_H
#define ACCOUNT_ACTIONS_H

// dependency header (data model)
#include "common/constants.h"
#include "../include/models/account_model.h"

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

Credentials change_credential_pipeline(Account* session, AccountOperationType type);
NotificationsStatus account_notifications_pipeline (Account* session, AccountNotificationsType type, bool enabled);
AccountStateStatus account_status_pipeline (Account* session, AccountStateOperationType type);


#endif