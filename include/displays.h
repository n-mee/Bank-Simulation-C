#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include "static_user.h"
// Success Msgs
void display_transfer_success(bool success, User* sender);
void display_withdraw_success(bool success, User* current_user);
void display_deposit_success(bool success, User* current_user);

// Error Msgs
void display_invalid_pin_msg();
void display_invalid_reciever_msg();
void display_error_bal_msg();
void display_invalid_selection_msg();

// Msgs
void display_farewell_msg();

#endif