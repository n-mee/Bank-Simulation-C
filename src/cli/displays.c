#include <stdio.h>
#include <stdbool.h>
#include "models/account_model.h"

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
