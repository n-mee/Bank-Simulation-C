#include <stdio.h>
#include "views/main_menu.h"

void header_menu(void) {
    printf("\n====================================\n");
    printf("          WELCOME TO BANK           ");
    printf("\n====================================\n");   
}

void choice_menu(void) {
    printf("\nOptions: \n");
    printf("\n1. Withdraw\n");
    printf("2. Deposit\n");
    printf("3. Transfer\n");
    printf("4. Settings\n");
    printf("0. Exit\n\n");
}