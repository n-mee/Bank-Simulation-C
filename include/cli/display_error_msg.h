#ifndef DISPLAY_ERROR_MSG_H
#define DISPLAY_ERROR_MSG_H

#include "common/exit_status.h"

/**
 * @brief dynamic msgs for errors in int input
 * @param status flag used for dynamic switching
*/
void invalid_integer_value(ParseExitResult status);

/**
 * @brief dynamic msgs for errors in double long int input
 * @param status flag used for dynamic switching
*/
void invalid_longlong_input(ParseExitResult status);

/**
 * @brief dynamic msgs for errors in yn input
 * @param status flag used for dynamic switching
*/
void invalid_bool_value(YesNoResult status);

/**
 * @brief dynamic msgs for errors in string input
 * @param status flag used for dynamic switching
*/
void invalid_string_value(ParsedStringResult status);

/**
 * @brief dynamic msgs for errors int account credentials operation
 * @param status flag used for dynamic switching
*/
void account_operation_error(Credentials status);

/**
 * @brief dynamic msgs for errors in notifications operation
 * @param status flag used for dynamic switching
*/
void account_notification_fail(NotificationsStatus status);

/**
 * @brief dynamic msgs for errors in account state operation
 * @param status flag used for dynamic switching
*/
void account_state_error(AccountStateStatus status);

/**
 * @brief dynamic msgs for errors in authentication
 * @param status flag used for dynamic switching
*/
void auth_operation_error(AuthStatus status);

/**
 * @brief dynamic msgs for errors in transaction operation
 * @param status flag used for dynamic switching
*/
void account_transaction_fail(TransactionStatus status);

/**
 * @brief dynamic msgs for errors in file operation
 * @param status flag used for dynamic switching
*/
void file_operation_error(FileStatus status);

/**
 * @brief standard "wrong choice" msg
*/
void invalid_selection_msg();

/**
 * @brief standard msg for pin limit error
*/
void invalid_pin_length();

#endif