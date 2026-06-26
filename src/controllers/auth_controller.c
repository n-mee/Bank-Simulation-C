#include "../include/views/displays.h"
#include "../include/utils/input_parser.h"
#include "../include/controllers/auth_controller.h"
#include "../include/data/database_manager.h"


void handle_registration(BankDatabase *db) {
    char temp_name[50];
    char temp_pin[6];

    get_string_prompt("Enter your name: ", temp_name, sizeof(temp_name));
    get_string_prompt("Enter your PIN: ", temp_pin, sizeof(temp_pin));

    int acc_id = db_account_creation(db, temp_name, temp_pin);

    if (acc_id == -1) {
        memory_allocation_error();
        return;
    }
    registration_success(&acc_id);
}