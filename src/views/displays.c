#include <stdio.h>
#include <stdbool.h>
#include "data/model.h"

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

void login_successful() {
    printf("Login success! Welcome Back!\n");
}

void invalid_search() {
    printf("[!] ERROR: Unique ID doesn't exist.\n");
}

void search_success() {
    printf("ID has been found.\n");
}

void registration_success(int *id) {
    printf("Registration successful! ID: %d\n", *id);
}

void memory_allocation_error() {
    printf("[!] ERROR: Memory Allocation failed.. Exiting..");
}

void invalid_pin_msg() {
    printf("[!] ERROR: Invalid PIN... Try Again.\n");
}

void invalid_reciever_msg(){
    printf("[!] ERROR: ID doesn't match any values in the database.\n");
}

void error_bal_msg() {
    printf("[!] ERROR: Amount should be greater than 0.\n");
}

void invalid_selection_msg() {
    printf("[!] ERROR: Invalid selection.\n");
}

void exit_msg() {
    printf("Exiting system... Goodbye.\n");
}

void wip_msg() {
    printf("[!] This feature is a Work-In-Progress (WIP)\n");
    printf("Come back again later\n");
}