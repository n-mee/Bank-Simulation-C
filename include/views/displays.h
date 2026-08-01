#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include "data/model.h"
// Success Msgs
void transfer_status(bool success, Account* sender);
void withdraw_status(bool success, Account* current_user);
void deposit_status(bool success, Account* current_user);
void registration_success(int *id);
void update_email_status(Account *session);
void change_pin_success(Account *session);
void change_name_success(Account *session);
void acc_limit_success(Account *session);
void txn_enable_msg(bool flag);
void push_enable_msg(bool flag);
void lowbal_enable_msg(bool flag);
void email_enable_msg(bool flag);
void acc_reactivation_success();
void acc_freeze_success();
void closed_acc_success();
void dir_init_success();
void search_success();
void login_successful();

// Error Msgs
void invalid_decimal_input();
void invalid_integer_input();
void empty_string_input();
void two_acc_status_inc();
void limit_out_range();
void acc_closed();
void dir_initiation_err();
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
void invalid_yn_choice();

// Msgs
void txn_notif_alr_on(bool flag);
void push_notif_alr_on(bool flag);
void lowbal_notif_alr_on(bool flag);
void email_notif_alr_on(bool flag);
void acc_is_frozen();
void acc_is_active();
void acc_is_closed(); 
void back_to_menu();
void wip_msg();
void exit_msg();

#endif