#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "common/file_utility.h"
#include "cli/displays.h"
#include "repositories/account_repository.h"

/**
 * @brief Geneators a Unique 2-digit ID
 * @param db Pointer referrence for duplication checking
 * @return The unique_id as an int to be assigned on a new account
 */
static int account_id_generator(BankDatabase *db) {
    int unique_id;
    int is_duplicate;
    do {
        // Unique ID generator from 10 - 99
        unique_id = (rand() % 90) + 10;
        is_duplicate = 0;
        // Linear index checker for duplication
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
    // Random seed for pure randomness
    srand(time(NULL));

    // Initializes database with set slots and default values
    db->db_capacity = init_slots;
    db->account_count = 0;
    // Allocates memory and return whether it succeeded
    db->records = calloc(init_slots, sizeof(Account));
    return (db->records != NULL);
}

// Database new account initializer
int db_account_creation(BankDatabase *db, Account new_acc) {
    // checks db size availability accordingly
    if (db->account_count >= db->db_capacity) {
        if (db_expand(db, db->db_capacity * 2) == -1){
            return -1;
        }
    }

    // Initializes the new account slot
    int index = db->account_count;
    db->records[index] = new_acc;
    db->records[index].accID = account_id_generator(db);
    db->records[index].bal = 0;

    // Increments database records and returns ID
    int new_id = db->records[index].accID;
    db->account_count++;
    return new_id;
}

// Database expander
int db_expand(BankDatabase *db, int capacity) {
    // checks db size availability accordingly
    if (capacity > db->db_capacity) {
        // increases the database size using the target capacity
        Account *temp = realloc(db->records, capacity * sizeof(Account));
        if (temp == NULL) return -1;
        db->records = temp;

        int new_accounts = capacity - db->db_capacity;
        memset(db->records + db->db_capacity, 0, new_accounts * sizeof(Account));

        db->db_capacity = capacity;
    }
    return 1;
}

// Linear scan search for indentity tracking
int db_find_identity(BankDatabase *db, int target_id) {
    for (int i = 0; i < db->account_count; i++) {
        // returns the account index if match found
        if (db->records[i].accID == target_id){
            return i;
        }
    }
    return -1;
}

// Terminates the database by freeing
void db_termination(BankDatabase *db){
    if (db->records != NULL) {
        free(db->records);
        // Set to null to avoid being used after freeing
        db->records = NULL;
    }
    db->account_count = 0;
    db->db_capacity = 0;
}