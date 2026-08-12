#include <stdio.h>
#include <stdbool.h>
#include "models/account_model.h"

void transfer_status(bool success, Account* sender){
    // Refers to the bool parameter and check what it returns.
    if (success){
        // Prints the "success" log along with the new balance of the sender.
        printf("Transfer Sucessful!\n");
        printf("Updated Balance: %.2lf.\n\n", sender->bal);
    } else {
        printf("[!] ERROR: Insufficient Balance to transfer.\n");
    }
}

void withdraw_status(bool success, Account* current_user){
    // Checks if the process of withdrawal returns true then prints the former condition.
    if (success) {
        printf("Withdrawal Successful!\n");
        printf("New Balance: %.2lf.\n\n", current_user->bal);
    // or prints the else if the withdrawal returns false.
    } else {
        printf("[!] ERROR: Insufficient Balance to Withdraw.\n");
    }
}

void deposit_status(bool success, Account* current_user){
    // Checks the process of deposit for boolean values and prints accordingly if it returns true
    if (success) {
        printf("Deposit Sucessful!\n");
        printf("New Balance: %.2lf.\n\n", current_user->bal);
    // or false.
    } else {
        printf("[!] ERROR: Deposit amount should be greater than 0.\n");
    }
}


void dir_init_success() {
    printf("Successfuly Initiated the directory.\n");
}

void dir_initiation_err() {
    fprintf(stderr, "[!] ERROR: Failed to initialize directory.\n");
}

void invalid_file () {
    printf("[!] ERROR: Invalid file.\n");
}

void invalid_search() {
    printf("[!] ERROR: Unique ID doesn't exist.\n");
}

void memory_allocation_error() {
    printf("[!] ERROR: Memory Allocation failed.. Exiting..");
}

void invalid_reciever_msg(){
    printf("[!] ERROR: ID doesn't match any values in the database.\n");
}

void self_transfer_error() {
    printf("[!] ERROR: Cannot transfer money to yourself.\n");
}

void error_bal_msg() {
    printf("[!] ERROR: Amount should be greater than 0.\n");
}

void invalid_selection_msg() {
    printf("[!] ERROR: Invalid selection.\n");
}

void back_to_menu() {
    printf("Exiting..\n");
    printf("Going back to menu..\n");
}

void exit_msg() {
    printf("Exiting system... Goodbye.\n");
}
