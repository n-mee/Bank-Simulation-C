#include <stdbool.h>
#include "data/model.h"
#include "core/transactions.h"
#include "auth/auth.h"
#include "controllers/handler.h"
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
    display_deposit_success(success, current_user);
}

// Handles the main withdraw logic.
void handle_withdraw_request(Account* current_user){
    if (!is_pin_valid(current_user->pin)) return;

    double withdraw_amt = get_amount();
    if (!is_valid_bal(withdraw_amt)) return;

    bool success = execute_withdraw(current_user, withdraw_amt);
    display_withdraw_success(success, current_user);
}

// Handles the main transfer logic.
void handle_transfer_request(Account* sender, Account* receiver){
    if(!is_pin_valid(sender->pin)) return;

    int r_id = get_receiver_id_input();
    if (!is_valid_receiver(r_id, receiver->accID)){
        display_invalid_reciever_msg();
        return;
    }

    double transfer_amt = get_amount();
    if(!is_valid_bal(transfer_amt)) return;

    bool success = execute_transfer(sender, receiver, transfer_amt);
    display_transfer_success(success, sender);
}