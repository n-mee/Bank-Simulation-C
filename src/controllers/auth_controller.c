#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "../include/views/displays.h"
#include "../include/utils/input_parser.h"
#include "../include/controllers/auth_controller.h"
#include "../include/data/database_functions.h"


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

void handle_login(BankDatabase *db, Account **session_user) {
    char temp_pin[6];
    int temp_id = get_int_prompt("Enter your Unique ID: ");

    int search_id = db_find_identity(db, temp_id);
    if (search_id == -1){
        invalid_search();
        *session_user = NULL;
        return;       
    }

    get_string_prompt("Enter your PIN: ", temp_pin, sizeof(temp_pin));
    if (strcmp(temp_pin, db->records[search_id].pin) != 0){
        wrong_pin_msg();
        *session_user = NULL;
        return;
    }

    *session_user = &db->records[search_id];
    login_successful();
}

bool is_pin_valid(const char* targetPIN){
    char tmp_buffer[10];

    get_string_prompt("Enter your pin: ", tmp_buffer, sizeof(tmp_buffer));

    if (strcmp(tmp_buffer, targetPIN) == 0) {
        return true;
    } else {
        return false;
    }
}