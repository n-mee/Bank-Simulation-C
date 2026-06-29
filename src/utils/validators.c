#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "utils/validators.h"
#include "views/displays.h"

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

bool is_valid_length_input(const char* target) {
    if (strlen(target) < 2) {
        invalid_str_size();
        return false;
    }
    return true;
}