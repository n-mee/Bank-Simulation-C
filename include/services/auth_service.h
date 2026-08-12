#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H

#include "repositories/account_repository.h"
#include "models/account_model.h"
#include "common/exit_status.h"

bool service_account_exists(BankDatabase *db, int id);
AuthStatus register_account(BankDatabase* db, Account raw_data, int *new_id);
AuthStatus authenticate_account(BankDatabase* db, int id, const char* pin, Account** session);

#endif