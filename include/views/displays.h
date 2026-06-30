#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include "data/model.h"
// Success Msgs
void transfer_status(bool success, Account* sender);
void withdraw_status(bool success, Account* current_user);
void deposit_status(bool success, Account* current_user);
void registration_success(int *id);
void change_pin_success(Account *session);
void change_name_success(Account *session);
void search_success();
void login_successful();

// Error Msgs
void self_transfer_error();
void invalid_str_size();
void invalid_file();
void invalid_search();
void memory_allocation_error();
void wrong_pin_msg();
void invalid_pin_msg();
void invalid_reciever_msg();
void error_bal_msg();
void invalid_selection_msg();

// Msgs
void back_to_menu();
void wip_msg();
void exit_msg();

#endif