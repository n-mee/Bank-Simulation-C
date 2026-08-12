#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include "../include/models/account_model.h"
// Success Msgs
void dir_init_success();

// Error Msgs
void dir_initiation_err();
void self_transfer_error();
void invalid_file();
void invalid_search();
void memory_allocation_error();
void invalid_reciever_msg();
void error_bal_msg();
void invalid_selection_msg();

// Msgs
void back_to_menu();
void exit_msg();

#endif