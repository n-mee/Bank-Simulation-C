#ifndef DISPLAY_ERROR_MSG_H
#define DISPLAY_ERROR_MSG_H

#include "common/exit_status.h"

void invalid_integer_value(ParseExitResult status);
void invalid_double_input(ParseExitResult status);
void invalid_bool_value(YesNoResult status);
void invalid_string_value(ParsedStringResult status);
void account_operation_error(Credentials status);
void account_notification_fail(NotificationsStatus status);
void account_state_error(AccountStateStatus status);
void invalid_pin_length();

#endif