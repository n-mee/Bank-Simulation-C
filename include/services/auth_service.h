#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H

#include "repositories/account_repository.h"
#include "models/account_model.h"
#include "common/exit_status.h"

/**
 * @brief looks up the id for matching existing accounts in the database
 * @param db database reference
 * @param id id look up reference
 * @return true if id is found, false if not
 */
bool service_account_exists(BankDatabase *db, int id);

/**
 * @brief register new account from controller and puts them into the database
 * @param db database reference
 * @param raw_data account struct to put into database
 * @param new_id pointer to newly generated id
 * @return returns an enum status code for error and success msg
 */
AuthStatus register_account(BankDatabase* db, Account raw_data, int *new_id);

/**
 * @brief authenticates account via id lookup, credentials verification
 * @param db database reference
 * @param id id reference to lookup to
 * @param pin standard pin credential to validate
 * @param session current active account
 * @return returns an enum status code for error and success msg
 */
AuthStatus authenticate_account(BankDatabase* db, int id, const char* pin, Account** session);

#endif