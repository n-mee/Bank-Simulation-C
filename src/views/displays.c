#include <stdio.h>
#include <stdbool.h>
#include "static_user.h"

void display_transfer_success(bool success, User* sender){
    // Refers to the bool parameter and check what it returns.
    if (success){
        // Prints the "success" log along with the new balance of the sender.
        printf("Transfer Sucessful!\n");
        printf("Updated Balance: %.2lf.\n\n", sender->bal);
    } else {
        printf("[!] ERROR: Insufficient Balance to transfer.\n");
    }
}

void display_withdraw_success(bool success, User* current_user){
    // Checks if the process of withdrawal returns true then prints the former condition.
    if (success) {
        printf("Withdrawal Successful!\n");
        printf("New Balance: %.2lf.\n\n", current_user->bal);
    // or prints the else if the withdrawal returns false.
    } else {
        printf("[!] ERROR: Insufficient Balance to Withdraw.\n");
    }
}

void display_deposit_success(bool success, User* current_user){
    // Checks the process of deposit for boolean values and prints accordingly if it returns true
    if (success) {
        printf("Deposit Sucessful!\n");
        printf("New Balance: %.2lf.\n\n", current_user->bal);
    // or false.
    } else {
        printf("[!] ERROR: Deposit amount should be greater than 0.\n");
    }
}

void display_invalid_pin_msg() {
    printf("[!] ERROR: Wrong PIN.\n");
}

void display_invalid_reciever_msg(){
    printf("[!] ERROR: ID doesn't match any id in the database.\n");
}

void display_error_bal_msg() {
    printf("[!] ERROR: Amount should be greater than 0.\n");
}

void display_invalid_selection_msg() {
    printf("[!] ERROR: Invalid selection.\n");
}

void display_farewell_msg() {
    printf("Exiting system. Goodbye.\n");
}