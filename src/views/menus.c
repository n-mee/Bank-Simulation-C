#include <stdio.h>
#include "views/menus.h"

void gateway_menu(void) {
    puts("+-------------------------------------+");
    puts("            Net-Bank Gateway           ");
    puts("+-------------------------------------+"); 
    puts("|                                     |");
    puts("|  [1] LOGIN                          |");
    puts("|  [2] REGISTER                       |");
    puts("|                                     |");
    puts("|  [0] EXIT                           |");
    puts("|                                     |");
    puts("+-------------------------------------+");
}

void main_menu(void) {
    puts("+-------------------------------------+");
    puts("         Net-Bank Secure Portal        ");
    puts("+-------------------------------------+"); 
    puts("|                                     |");
    puts("|  [1] WITHDRAW                       |");
    puts("|  [2] DEPOSIT                        |");
    puts("|  [3] TRANSFER                       |");
    puts("|  [4] ACCOUNT SETTINGS               |");
    puts("|                                     |");
    puts("|  [0] EXIT                           |");
    puts("|                                     |");
    puts("+-------------------------------------+");
}

void account_menu(void) {
    puts("+-------------------------------------+");
    puts("            Account Settings           ");
    puts("+-------------------------------------+");
    puts("|                                     |");
    puts("|   [1] PROFILE SETTINGS              |");
    puts("|   [2] PREFERENCE SETTINGS           |");
    puts("|   [3] CARD AND PAYMENT CONTROLS     |");
    puts("|                                     |");
    puts("|   [0] EXIT                          |");
    puts("|                                     |");
    puts("+-------------------------------------+");
}