#ifndef ACCOUNT_ACTIONS_H
#define ACCOUNT_ACTIONS_H

#include "../include/data/model.h"

void account_update_pin(Account *session, const char* new_pin);
void account_update_name(Account *session, const char* new_pin);

#endif