#ifndef ACCOUNT_REPOSITORY_H
#define ACCOUNT_REPOSITORY_H

// dependency header (one used for pointers inside struct)
#include "../include/models/account_model.h"

// Database struct 
typedef struct {
    // points to the struct model in the dependency header
    Account *records;
    /*  
        Code below acts as a allocator
        and storage limt for structs
        they count how many accs are active
        and capacity acts as a storage size
        limiter
    */
    int account_count;
    int db_capacity;
} BankDatabase;





/* ======================================
 *         DATABASE FUNCTIONS
 * ======================================
*/

/**
 * @brief Initializes the Database and Allocates slots on the heap
 * @param db Pointer referrence for initialization
 * @param init_slots The initial slots to allocate on the heap
 * @return Returns true if initalization succeeded, returns false if it fails
*/
int db_init(BankDatabase *db, int init_slots);

/**
 * @brief Allocates more space in the master account database
 * @param db Points to the master database structure
 * @param capacity Target capacity for expansion of database
 * @return Allocation returns 1 if success, -1 if fail
 */
int db_expand(BankDatabase *db, int capacity);

/**
 * @brief Creates an account and assigns it into heap via db
 * @param db Pointer reference to access database data
 * @param name Name string with null termination
 * @param pin Final string value of pin (truncated if input exceeds array size)
 * @return negative one if it fails at allocating ram space, return the ID if success
 */
int db_account_creation(BankDatabase *db, Account new_acc);

/**
 * @brief Linear scan for identity matching
 * @param db Points to the masters struct data structure
 * @param target_id reference for linear scan search
 * @return The account index if found, returns -1 if fails to find
 */
int db_find_identity(BankDatabase *db, int target_id);

/**
 * @brief Frees the allocated memory database and nulls its value
 * @param db Pointer reference for database
 */
void db_termination(BankDatabase *db);





/* ====================================
 *            SERIALIZATION
 * ====================================
 */

/**
 * TODO: Fix return type from void to exit status
 * 
 * 
 * @brief Saves the state of database as a binary file (.bin/wb)
 * @param db The database to be saved
 */
void db_save_to_file(BankDatabase *db);

/** 
 * TODO: Fix return type to ensure the function operation is successful
 *       or not
 * 
 * 
 * @brief Loads the database state from file into the struct database
 * @param db The actual database to pass its structure to
 */
void db_load_from_file(BankDatabase *db);


#endif