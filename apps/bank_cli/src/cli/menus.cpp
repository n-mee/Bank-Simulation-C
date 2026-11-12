#include <iostream>
#include "cli/menus.hpp"

void Menu::TerminalGateway(void) {
    std::cout << "+-------------------------------------+\n";
    std::cout << "            Net-Bank Gateway           \n";
    std::cout << "+-------------------------------------+\n"; 
    std::cout << "|                                     |\n";
    std::cout << "|   [1] LOGIN                         |\n";
    std::cout << "|   [2] REGISTER                      |\n";
    std::cout << "|                                     |\n";
    std::cout << "|   [0] EXIT                          |\n";
    std::cout << "|                                     |\n";
    std::cout << "+-------------------------------------+\n";
}

void Menu::TerminalMain(void) {
    std::cout << "+-------------------------------------+\n";
    std::cout << "         Net-Bank Secure Portal        \n";
    std::cout << "+-------------------------------------+\n"; 
    std::cout << "|                                     |\n";
    std::cout << "|   [1] WITHDRAW                      |\n";
    std::cout << "|   [2] DEPOSIT                       |\n";
    std::cout << "|   [3] TRANSFER                      |\n";
    std::cout << "|   [4] ACCOUNT SETTINGS              |\n";
    std::cout << "|                                     |\n";
    std::cout << "|   [0] EXIT                          |\n";
    std::cout << "|                                     |\n";
    std::cout << "+-------------------------------------+\n";
}

void Menu::AccountSettings(void) {
    std::cout << "+-------------------------------------+\n";
    std::cout << "            Account Settings           \n";
    std::cout << "+-------------------------------------+\n";
    std::cout << "|                                     |\n";
    std::cout << "|   [1] PROFILE SETTINGS              |\n";
    std::cout << "|   [2] PREFERENCE SETTINGS           |\n";
    std::cout << "|   [3] CARD AND PAYMENT CONTROLS     |\n";
    std::cout << "|                                     |\n";
    std::cout << "|   [0] EXIT                          |\n";
    std::cout << "|                                     |\n";
    std::cout << "+-------------------------------------+\n";
}

void Menu::ProfileSettings(void) {
    std::cout << "+-------------------------------------+\n";
    std::cout << "            Profile Settings           \n";
    std::cout << "+-------------------------------------+\n";
    std::cout << "|                                     |\n";
    std::cout << "|    [1] Change Username              |\n";
    std::cout << "|    [2] Change E-mail                |\n";
    std::cout << "|    [3] Change Pin                   |\n";
    std::cout << "|                                     |\n";
    std::cout << "|    [0] EXIT                         |\n";
    std::cout << "|                                     |\n";
    std::cout << "+-------------------------------------+\n";
}

void Menu::NotificationSettings(void) {
    std::cout << "+-------------------------------------+\n";
    std::cout << "          Preference Settings          \n";
    std::cout << "+-------------------------------------+\n";
    std::cout << "|                                     |\n";
    std::cout << "|   [1] Email Notifications           |\n";
    std::cout << "|   [2] Push Notifications            |\n";
    std::cout << "|   [3] Alert Notifications           |\n";
    std::cout << "|                                     |\n";
    std::cout << "|   [0] EXIT                          |\n";
    std::cout << "|                                     |\n";
    std::cout << "+-------------------------------------+\n";
}

void Menu::AlertSettings(void) {
    std::cout << "+-------------------------------------+\n";
    std::cout << "          Alert Notifications          \n";
    std::cout << "+-------------------------------------+\n";
    std::cout << "|                                     |\n";
    std::cout << "|   [1] Low Balance Alerts            |\n";
    std::cout << "|   [2] Large Transaction Alerts      |\n";
    std::cout << "|                                     |\n";
    std::cout << "|   [0] EXIT                          |\n";
    std::cout << "|                                     |\n";
    std::cout << "+-------------------------------------+\n";
}

void Menu::PaymentSettings(void) {
    std::cout << "+-------------------------------------+\n";
    std::cout << "            Payment Settings           \n";
    std::cout << "+-------------------------------------+\n";
    std::cout << "|                                     |\n";
    std::cout << "|   [1] Account Status                |\n";
    std::cout << "|   [2] Daily Limit                   |\n";
    std::cout << "|                                     |\n";
    std::cout << "|   [0] EXIT                          |\n";
    std::cout << "|                                     |\n";
    std::cout << "+-------------------------------------+\n";
}

void Menu::AccountStatusSettings(void) {
    std::cout << "+-------------------------------------+\n";
    std::cout << "             Account Status            \n";
    std::cout << "+-------------------------------------+\n";
    std::cout << "|                                     |\n";
    std::cout << "|   [1] Freeze Account                |\n";
    std::cout << "|   [2] Unfreeze Account              |\n";
    std::cout << "|   [3] Close Account                 |\n";
    std::cout << "|                                     |\n";
    std::cout << "|   [0] EXIT                          |\n";
    std::cout << "|                                     |\n";
    std::cout << "+-------------------------------------+\n";
}