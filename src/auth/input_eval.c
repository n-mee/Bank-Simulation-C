#include <stdbool.h>
#include "utils/input_parser.h"
#include "views/displays.h"
#include "auth/auth.h"

bool is_pin_valid(int targetPIN){
    int tmp_pin = get_int_prompt("Enter your pin: ");

    if (tmp_pin != targetPIN) {
        display_invalid_pin_msg();
        return false;
    }
    return true;
}

bool is_valid_receiver(int referrence, int target){
    if (referrence != target || referrence <= -1){
        return false;
    }
    return true;
}