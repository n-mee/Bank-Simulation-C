#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "common/exit_status.h"
#include "repositories/account_repository.h"

FileStatus load_from_file(BankDatabase *db);
FileStatus save_to_file(BankDatabase *db);

#endif