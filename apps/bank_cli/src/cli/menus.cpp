#include <iostream>
#include "cli/menus.hpp"

void Menu::TerminalGateway(void) {
    std::cout << "+-------------------------------------+";
    std::cout << "            Net-Bank Gateway           ";
    std::cout << "+-------------------------------------+"; 
    std::cout << "|                                     |";
    std::cout << "|   [1] LOGIN                         |";
    std::cout << "|   [2] REGISTER                      |";
    std::cout << "|                                     |";
    std::cout << "|   [0] EXIT                          |";
    std::cout << "|                                     |";
    std::cout << "+-------------------------------------+";
}

void Menu::TerminalMain(void) {
    std::cout << "+-------------------------------------+";
    std::cout << "         Net-Bank Secure Portal        ";
    std::cout << "+-------------------------------------+"; 
    std::cout << "|                                     |";
    std::cout << "|   [1] WITHDRAW                      |";
    std::cout << "|   [2] DEPOSIT                       |";
    std::cout << "|   [3] TRANSFER                      |";
    std::cout << "|   [4] ACCOUNT SETTINGS              |";
    std::cout << "|                                     |";
    std::cout << "|   [0] EXIT                          |";
    std::cout << "|                                     |";
    std::cout << "+-------------------------------------+";
}

void Menu::AccountSettings(void) {
    std::cout << "+-------------------------------------+";
    std::cout << "            Account Settings           ";
    std::cout << "+-------------------------------------+";
    std::cout << "|                                     |";
    std::cout << "|   [1] PROFILE SETTINGS              |";
    std::cout << "|   [2] PREFERENCE SETTINGS           |";
    std::cout << "|   [3] CARD AND PAYMENT CONTROLS     |";
    std::cout << "|                                     |";
    std::cout << "|   [0] EXIT                          |";
    std::cout << "|                                     |";
    std::cout << "+-------------------------------------+";
}

void Menu::ProfileSettings(void) {
    std::cout << "+-------------------------------------+";
    std::cout << "            Profile Settings           ";
    std::cout << "+-------------------------------------+";
    std::cout << "|                                     |";
    std::cout << "|    [1] Change Username              |";
    std::cout << "|    [2] Change E-mail                |";
    std::cout << "|    [3] Change Pin                   |";
    std::cout << "|                                     |";
    std::cout << "|    [0] EXIT                         |";
    std::cout << "|                                     |";
    std::cout << "+-------------------------------------+";
}

void Menu::NotificationSettings(void) {
    std::cout << "+-------------------------------------+";
    std::cout << "          Preference Settings          ";
    std::cout << "+-------------------------------------+";
    std::cout << "|                                     |";
    std::cout << "|   [1] Email Notifications           |";
    std::cout << "|   [2] Push Notifications            |";
    std::cout << "|   [3] Alert Notifications           |";
    std::cout << "|                                     |";
    std::cout << "|   [0] EXIT                          |";
    std::cout << "|                                     |";
    std::cout << "+-------------------------------------+";
}

void Menu::AlertSettings(void) {
    std::cout << "+-------------------------------------+";
    std::cout << "          Alert Notifications          ";
    std::cout << "+-------------------------------------+";
    std::cout << "|                                     |";
    std::cout << "|   [1] Low Balance Alerts            |";
    std::cout << "|   [2] Large Transaction Alerts      |";
    std::cout << "|                                     |";
    std::cout << "|   [0] EXIT                          |";
    std::cout << "|                                     |";
    std::cout << "+-------------------------------------+";
}

void Menu::PaymentSettings(void) {
    std::cout << "+-------------------------------------+";
    std::cout << "            Payment Settings           ";
    std::cout << "+-------------------------------------+";
    std::cout << "|                                     |";
    std::cout << "|   [1] Account Status                |";
    std::cout << "|   [2] Daily Limit                   |";
    std::cout << "|                                     |";
    std::cout << "|   [0] EXIT                          |";
    std::cout << "|                                     |";
    std::cout << "+-------------------------------------+";
}

void Menu::AccountStatusSettings(void) {
    std::cout << "+-------------------------------------+";
    std::cout << "             Account Status            ";
    std::cout << "+-------------------------------------+";
    std::cout << "|                                     |";
    std::cout << "|   [1] Freeze Account                |";
    std::cout << "|   [2] Unfreeze Account              |";
    std::cout << "|   [3] Close Account                 |";
    std::cout << "|                                     |";
    std::cout << "|   [0] EXIT                          |";
    std::cout << "|                                     |";
    std::cout << "+-------------------------------------+";
}