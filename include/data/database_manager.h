#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include "../include/data/model.h"

typedef struct {
    Account *records;
    int account_count;
    int db_capacity;
} BankDatabase;

int db_init(BankDatabase *db, int init_slots);
int db_account_creation(BankDatabase *db, const char *name, const char *pin);
void db_termination(BankDatabase *db);


#endif