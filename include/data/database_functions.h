#ifndef DATABASE_FUNCTIONS_H
#define DATABASE_FUNCTIONS_H

#include <stdbool.h>
#include "../include/data/model.h"

typedef struct {
    Account *records;
    int account_count;
    int db_capacity;
} BankDatabase;

int db_init(BankDatabase *db, int init_slots);
int db_account_creation(BankDatabase *db, const char *name, const char *pin);
int db_find_identity(BankDatabase *db, int target_id);
void db_termination(BankDatabase *db);
bool is_valid_receiver(int referrence, int target);


#endif