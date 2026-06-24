#include <stdio.h>
#include "views/main_menu.h"

void header_menu(void) {
    puts("\n+-------------------------------------+");
    puts("         Net-Bank Secure Portal           ");
    puts("+-------------------------------------+");   
}

void choice_menu(void) {
    puts("|                                     |");
    puts("|  [1] Withdraw                       |");
    puts("|  [2] Deposit                        |");
    puts("|  [3] Transfer                       |");
    puts("|  [4] Account Setting (WIP)          |");
    puts("|                                     |");
    puts("|  [0] Exit                           |");
    puts("|                                     |");
    puts("+-------------------------------------|");
}