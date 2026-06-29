#ifndef ACCOUNT_CONTROLLER_H
#define ACCOUNT_CONTROLLER_H

//header
#include "../include/data/model.h"

// function
void change_pin_pipeline(Account *session);
void change_name_pipeline(Account *session);
void handle_account_settings(Account *current_session);

#endif