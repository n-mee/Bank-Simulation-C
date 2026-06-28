#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/views/displays.h"
#include "../include/data/database_manager.h"

static int account_id_generator(BankDatabase *db) {
    int unique_id;
    int is_duplicate;
    do {
        unique_id = (rand() % 90) + 10;
        is_duplicate = 0;
        for (int i = 0; i < db->account_count; i++) {
            if (db->records[i].accID == unique_id) {
                is_duplicate = 1;
                break;
            }
        }
    }while (is_duplicate);
    return unique_id;
}

int db_init(BankDatabase *db, int init_slots) {
    // random seed for pure randomness
    srand(time(NULL));

    // initializaiton of data
    db->db_capacity = init_slots;
    db->account_count = 0;
    // actual data initialization
    db->records = malloc(init_slots * sizeof(Account));
    // returns the 1 if successful and 0 if failed.
    return (db->records != NULL);
}

// Account creation function that also automatically adds new accs
int db_account_creation(BankDatabase *db, const char *name, const char *pin) {
    // checks db size availability accordingly
    if (db->account_count >= db->db_capacity) {
        // increases the database by 2
        int new_capacity = db->db_capacity * 2;
        Account *temp = realloc(db->records, new_capacity * sizeof(Account));
        if (temp == NULL) return -1;
        db->records = temp;
        db->db_capacity = new_capacity;
    }

    int index = db->account_count;
    db->records[index].accID = account_id_generator(db);
    db->records[index].bal = 0.0;
    
    strncpy(db->records[index].name, name, sizeof(db->records[index].name) - 1);
    db->records[index].name[sizeof(db->records[index].name) - 1] = '\0';
    strncpy(db->records[index].pin, pin, sizeof(db->records[index].pin) - 1);
    db->records[index].pin[sizeof(db->records[index].pin) - 1] = '\0';

    int new_id = db->records[index].accID;
    db->account_count++;
    return new_id;
}

int db_find_identity(BankDatabase *db, int target_id) {
    for (int i = 0; i < db->account_count; i++) {
        if (db->records[i].accID == target_id){
            return i;
        }
    }
    return -1;
}

void db_termination(BankDatabase *db){
    if (db->records != NULL) {
        free(db->records);
        db->records = NULL;
    }
    db->account_count = 0;
    db->db_capacity = 0;
}