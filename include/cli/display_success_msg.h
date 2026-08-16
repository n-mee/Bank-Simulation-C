#ifndef DISPLAY_SUCCESS_MSG_H
#define DISPLAY_SUCCESS_MSG_H

#include "models/account_model.h"
#include "common/constants.h"
#include "common/exit_status.h"

/**
 * @brief dynamic status msg for success operations in credentials
 * @param type flag for dynamic switching
 */
void account_operation_success(AccountOperationType type);

/**
 * @brief dynamic status msg for success operations in notifications
 * @param type reference for printing if account notif flag are ON or OFF
 * @param status flag for dynamic switching
 */
void account_notification_status(AccountNotificationsType type, NotificationsStatus status);

/**
 * @brief dynamic status msg for success operations in account status
 * @param type flag for dynamic switcing depending on operation type
 */
void account_state_success(AccountStateOperationType type);

/**
 * @brief dynamic status msg on authentication operation
 * @param status flag for dynamic switching
 * @param new_id pointer reference for printing user id
 * @param session reference for account info for login operation
 */
void auth_operation_success(AuthStatus status, const int* new_id, const Account* session);

/**
 * @brief dynamic status msg for transaction operation
 * @param type flag for dynamic switching depending on operation type
 */
void account_transaction_success(TransactionType type);

/**
 * @brief dynamic status msg for file operations (e.g logging)
 * @param status flag for dynamic switching
 */
void file_operation_success(FileStatus status);

#endif