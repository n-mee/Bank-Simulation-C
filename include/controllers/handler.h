#ifndef HANDLER_H
#define HANDLER_H

// Transact Handlers
#include "data/static_user.h"
void handle_withdraw_request(User* current_user);
void handle_deposit_request(User* current_user);
void handle_transfer_request(User* sender, User* receiver);

//Input Handler
#endif