#pragma once

#include "common/exit_status.hpp"
#include "account_repository.hpp"

/**
 * @brief loads the data from the file into the database
 * @param db pointer reference for the database
 * @return custom status codes for logging and error msg
 */
FileStatus load_from_file(BankDatabase *db);

/**
 * @brief saves the database into a file
 * @param db pointer reference for the database
 * @return custom status code for logging and error msg
 */
FileStatus save_to_file(BankDatabase *db);