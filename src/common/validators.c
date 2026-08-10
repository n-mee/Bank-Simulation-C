#include "common/validators.h"
#include "common/value_parser.h"
#include "cli/displays.h"

// checks if the amount entered is valid and returns the according boolean values.
bool is_valid_bal(double amt) {
    if (amt <= 0) {
        error_bal_msg();
        return false;
    }
    return true;
}

bool is_valid_pin(const char* target_pin, const char* input_pin) {
    if (strcmp(target_pin, input_pin) != 0) {
        invalid_pin_msg();
        return false;
    }
    return true;
}

bool is_valid_pin_length(const char* target_pin) {
    if (target_pin == NULL) return false;

    return strlen(target_pin) == PIN_LENGTH;
}

bool is_valid_length_input(const char* target, int limit_len) {
    if (strlen(target) <= (size_t)limit_len) {
        invalid_str_size();
        return false;
    }
    return true;
}

bool is_valid_id(int referrence, int target){
    if (referrence != target || referrence <= -1){
        return false;
    }
    return true;
}

bool is_valid_limit(const double* target) {
    double lowest_limit = 10000.00;
    double highest_limit = 50000.00;

    if (target == NULL) {
        return false;
    }

    if (*target < lowest_limit || *target > highest_limit) {
        return false;
    }
    return true;
}