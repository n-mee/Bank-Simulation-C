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

void profile_settings(void) {
    puts("+-------------------------------------+");
    puts("            Profile Settings           ");
    puts("+-------------------------------------+");
    puts("|                                     |");
    puts("|   [1] Change Username               |");
    puts("|   [2] Change E-mail                 |");
    puts("|   [3] Change Pin                    |");
    puts("|                                     |");
    puts("|   [0] EXIT                          |");
    puts("|                                     |");
    puts("+-------------------------------------+");
}

void preference_settings(void) {
    puts("+-------------------------------------+");
    puts("          Preference Settings          ");
    puts("+-------------------------------------+");
    puts("|                                     |");
    puts("|   [1] Email Notifications           |");
    puts("|   [2] Push Notifications            |");
    puts("|   [3] Alert Notifications           |");
    puts("|                                     |");
    puts("|   [0] EXIT                          |");
    puts("|                                     |");
    puts("+-------------------------------------+");
}

void alert_pref_settings(void) {
    puts("+-------------------------------------+");
    puts("          Alert Notifications          ");
    puts("+-------------------------------------+");
    puts("|                                     |");
    puts("|   [3] Low Balance Alerts            |");
    puts("|   [4] Large Transaction Alerts      |");
    puts("|                                     |");
    puts("|   [0] EXIT                          |");
    puts("|                                     |");
    puts("+-------------------------------------+");
}

void payment_settings(void) {
    puts("+-------------------------------------+");
    puts("            Payment Settings           ");
    puts("+-------------------------------------+");
    puts("|                                     |");
    puts("|   [1] Account Status                |");
    puts("|   [2] Daily Limit                   |");
    puts("|                                     |");
    puts("|   [0] EXIT                          |");
    puts("|                                     |");
    puts("+-------------------------------------+");
}

void account_status_menu(void) {
    puts("+-------------------------------------+");
    puts("             Account Status            ");
    puts("+-------------------------------------+");
    puts("|                                     |");
    puts("|   [1] Freeze Account                |");
    puts("|   [2] Unfreeze Account              |");
    puts("|   [3] Close Account                 |");
    puts("|                                     |");
    puts("|   [0] EXIT                          |");
    puts("|                                     |");
    puts("+-------------------------------------+");
}