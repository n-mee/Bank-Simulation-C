#include "common/validators.h"
#include "common/constants.h"

bool is_valid_pin(const char* target_pin, const char* input_pin) {
    if (strcmp(target_pin, input_pin) != 0) {
        return false;
    }
    return true;
}

bool is_valid_pin_length(const char* target_pin) {
    if (target_pin == NULL) return false;

    return strlen(target_pin) == PIN_LENGTH;
}

bool is_valid_length_input(const char* target, int limit_len) {
    if (target == NULL) return false;

    return strlen(target) >= (size_t)limit_len;
}

bool is_valid_id(int referrence, int target){
    if (referrence != target || referrence <= -1){
        return false;
    }
    return true;
}

bool is_valid_limit(const long long *target) {
    if (target == NULL) return false;
    
    return (*target >= 10000 && *target <= 50000);
}
