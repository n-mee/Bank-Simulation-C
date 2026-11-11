#pragma once
// dependency header (data model)
#include "common/exit_status.hpp"
#include "common/constants.hpp"
#include "domain/account_model.hpp"

/**
 * @brief handles the process of changing user credentials depending on operation type
 * @param session reference for current active user
 * @param type flag reference for dynamic operation switching
 * @return returns an enum code for errors and success operations
 */
Credentials change_credential_pipeline(Account* session, AccountOperationType type);

/**
 * @brief handles the operation for setting notifications and alert flag
 * @param session reference for current active user
 * @param type flag reference for dynamic operation switching
 * @param enabled flag state used for setting account notifs and alerts flag
 * @return returns an enum code for errors and success operations
 */
NotificationsStatus account_notifications_pipeline (Account* session, AccountNotificationsType type, bool enabled);

/**
 * @brief handles operation for account state and limit
 * @param session reference for current active account
 * @param type flag reference used for dynamic operation switching
 * @return returns an enum code for errors and success operations
 */
AccountStateStatus account_status_pipeline (Account* session, AccountStateOperationType type);