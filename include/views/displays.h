#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include "data/model.h"
// Success Msgs
void display_transfer_success(bool success, Account* sender);
void display_withdraw_success(bool success, Account* current_user);
void display_deposit_success(bool success, Account* current_user);
void registration_success(int *id);
void search_success();
void login_successful();

// Error Msgs
void invalid_search();
void memory_allocation_error();
void display_invalid_pin_msg();
void display_invalid_reciever_msg();
void display_error_bal_msg();
void display_invalid_selection_msg();

// Msgs
void wip_msg();
void display_farewell_msg();

#endif