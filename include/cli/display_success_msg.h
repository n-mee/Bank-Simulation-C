#ifndef DISPLAY_SUCCESS_MSG_H
#define DISPLAY_SUCCESS_MSG_H

#include "common/constants.h"
#include "common/exit_status.h"

void account_operation_success(AccountOperationType type);
void account_notification_status(AccountNotificationsType type, NotificationsStatus status);
void account_state_success(AccountStateOperationType type);

#endif