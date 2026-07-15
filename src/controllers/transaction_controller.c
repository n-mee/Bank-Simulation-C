#include <stdbool.h>
#include "data/database_functions.h"
#include "data/model.h"
#include "core/transactions.h"
#include "controllers/auth_controller.h"
#include "utils/validators.h"
#include "views/input.h"
#include "views/displays.h"

// Handles the main deposit logic.
void handle_deposit_request(Account* current_user){
    char PIN[6];
    get_pin(PIN);
    // check for valid pin
    if (!is_valid_pin(current_user->pin, PIN)) return;

    // Gets the amount and checks if the amount is valid.
    double deposit_amt = get_amount();
    if (!is_valid_bal(deposit_amt)) return;

    // executes the main code and prints the result.
    bool success = execute_deposit(current_user, deposit_amt);
    deposit_status(success, current_user);
}

// Handles the main withdraw logic.
void handle_withdraw_request(Account* current_user){
    char PIN[6];
    get_pin(PIN);
    // check for valid pin
    if (!is_valid_pin(current_user->pin, PIN)) return;

    // handles the withdraw input and verifies the balance
    double withdraw_amt = get_amount();
    if (!is_valid_bal(withdraw_amt)) return;

    // handles the main business logic of bank and returns boolean if it succeed or not
    bool success = execute_withdraw(current_user, withdraw_amt);
    withdraw_status(success, current_user);
}

// Handles the main transfer logic.
void handle_transfer_request(BankDatabase *db, Account *sender){
    char PIN[6];
    get_pin(PIN);
    // check for valid pin
    if (!is_valid_pin(sender->pin, PIN)) return;
    // get the id of the reciever
    int r_id = get_receiver_id_input();
    // check if the reciever's id is in the database
    int id_found = db_find_identity(db, r_id);
    // if not it prints an error and closes
    if (id_found == -1) {
        invalid_reciever_msg();
        return;
    }

    // this logic prevents self-transfer
    if (db->records[id_found].accID == sender->accID) {
        self_transfer_error();
        return;
    }

    // if id is found, we use a stack struct to transfer values
    Account *receiver = &db->records[id_found];

    // gets the balance amount and verifies its validity
    double transfer_amt = get_amount();
    if(!is_valid_bal(transfer_amt)) return;

    // handles the main logic of the transfer and returns the status of the transfer
    bool success = execute_transfer(sender, receiver, transfer_amt);
    transfer_status(success, sender);
}