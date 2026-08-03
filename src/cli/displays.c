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

void acc_limit_success(Account *session) {
    printf("Sucessfully set a new limit: %.2f.\n", session->controls.daily_limit);
}

void txn_enable_msg(bool flag) {
    printf("\nLarge transactions are notifications are now %s.\n", flag ? "ENABLED" : "DISABLED");
}

void push_enable_msg(bool flag) {
    printf("\nPush notifications are now %s.\n", flag ? "ENABLED" : "DISABLED");
}

void lowbal_enable_msg(bool flag) {
    printf("\nLow balance alert notifications are now %s.\n", flag ? "ENABLED" : "DISABLED");
}

void email_enable_msg(bool flag) {
    printf("\nEmail notifications are now %s.\n", flag ? "ENABLED" : "DISABLED");
}

void dir_init_success() {
    printf("Successfuly Initiated the directory.\n");
}

void login_successful() {
    printf("Login success! Welcome Back!\n");
}

void update_email_status(Account *session) {
    printf("Successfully changed your email!\n");
    printf("Your new email: %s\n", session->profile.email);
}

void change_pin_success(Account *session) {
    printf("Change of PIN: [SUCCESS!!]\n");
    printf("Your new PIN: %s\n", session->profile.pin);
}

void change_name_success(Account *session) {
    printf("Change of display name: [SUCCESS!!]\n");
    printf("Your new display name: %s\n", session->profile.name);
}

void acc_reactivation_success() {
    printf("Successfully re-activated the account.\n");
}

void acc_freeze_success() {
    printf("Successfully freezed the account.\n");
}

void closed_acc_success() {
    printf("Successfully CLOSED the account.\n");
}

void empty_string_input() {
    printf("[!] ERROR: Input cannot be empty. Try again.\n");
}

void invalid_decimal_input() {
    printf("[!] ERROR: Please enter valid decimals only.\n");
}

void invalid_integer_input() {
    printf("[!] ERROR: Please enter valid number.\n");
}

void acc_closed() {
    printf("Closed accounts are unaccessible.\n");
}

void two_acc_status_inc() {
    printf("Cannot FREEZE an already CLOSED account.\n");
}

void dir_initiation_err() {
    fprintf(stderr, "[!] ERROR: Failed to initialize directory.\n");
}

void invalid_str_size() {
    printf("[!] ERROR: Invalid string input.\n");
}

void invalid_file () {
    printf("[!] ERROR: Invalid file.\n");
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

void limit_out_range() {
    printf("Limit should only be between 10k-50k. Try again..\n");
}

void memory_allocation_error() {
    printf("[!] ERROR: Memory Allocation failed.. Exiting..");
}

void wrong_pin_msg() {
    printf("[!] ERROR: Wrong PIN.\n");
}

void invalid_pin_msg() {
    printf("[!] ERROR: Invalid PIN... Try Again.\n");
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

void acc_is_frozen() {
    printf("Your account is already frozen.\n");
}

void invalid_yn_choice() {
    printf("\nInvalid choice. Please type 'yes' or 'no'.\n");
}

void acc_is_active() {
    printf("Successfully re-activated the account.\n");
}

void acc_is_closed() {
    printf("Your account is already CLOSED.\n");
}

void txn_notif_alr_on(bool flag) {
    printf("Your large transactions alert notifications are already %s.\n", flag ? "ENABLED" : "DISABLED");
}

void push_notif_alr_on(bool flag) {
    printf("Your push notifications are already %s.\n", flag ? "ENABLED" : "DISABLED");
}

void lowbal_notif_alr_on(bool flag) {
    printf("Your low balance alert notifications are already %s.\n", flag ? "ENABLED" : "DISABLED");
}

void email_notif_alr_on(bool flag) {
    printf("Your email notifications are already %s.\n", flag ? "ENABLED" : "DISABLED");
}

void back_to_menu() {
    printf("Exiting..\n");
    printf("Going back to menu..\n");
}

void exit_msg() {
    printf("Exiting system... Goodbye.\n");
}

void wip_msg() {
    printf("[!] This feature is a Work-In-Progress (WIP)\n");
    printf("Come back again later\n");
}