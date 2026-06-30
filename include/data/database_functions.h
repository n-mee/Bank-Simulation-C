#ifndef DATABASE_FUNCTIONS_H
#define DATABASE_FUNCTIONS_H

#include "../include/data/model.h"

typedef struct {
    Account *records;
    int account_count;
    int db_capacity;
} BankDatabase;

// actual database functions
int db_init(BankDatabase *db, int init_slots);
int db_expand(BankDatabase *db, int capacity);
int db_account_creation(BankDatabase *db, const char *name, const char *pin);
int db_find_identity(BankDatabase *db, int target_id);
void db_termination(BankDatabase *db);

//serialization
void db_save_to_file(BankDatabase *db);
void db_load_from_file(BankDatabase *db);


#endif