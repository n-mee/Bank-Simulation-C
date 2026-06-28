#include <stdbool.h>
#include "data/database_manager.h"
#include "data/model.h"
#include "core/transactions.h"
#include "auth/auth.h"
#include "views/input.h"
#include "views/displays.h"

// Handles the main deposit logic.
void handle_deposit_request(Account* current_user){
    // Checks and validates the id
    if (!is_pin_valid(current_user->pin)) return;

    // Gets the amount and checks if the amount is valid.
    double deposit_amt = get_amount();
    if (!is_valid_bal(deposit_amt)) return;

    // executes the main code and prints the result.
    bool success = execute_deposit(current_user, deposit_amt);
    deposit_status(success, current_user);
}

// Handles the main withdraw logic.
void handle_withdraw_request(Account* current_user){
    if (!is_pin_valid(current_user->pin)) return;

    double withdraw_amt = get_amount();
    if (!is_valid_bal(withdraw_amt)) return;

    bool success = execute_withdraw(current_user, withdraw_amt);
    withdraw_status(success, current_user);
}

// Handles the main transfer logic.
void handle_transfer_request(BankDatabase *db, Account *sender){
    if(!is_pin_valid(sender->pin)) return;

    int r_id = get_receiver_id_input();
    int id_found = db_find_identity(db, r_id);
    if (id_found == -1) {
        invalid_reciever_msg();
        return;
    }

    Account *receiver = &db->records[id_found];

    double transfer_amt = get_amount();
    if(!is_valid_bal(transfer_amt)) return;

    bool success = execute_transfer(sender, receiver, transfer_amt);
    transfer_status(success, sender);
}