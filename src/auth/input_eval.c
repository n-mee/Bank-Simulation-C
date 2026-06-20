#include <stdbool.h>
#include <string.h>
#include "utils/input_parser.h"
#include "views/displays.h"
#include "auth/auth.h"

bool is_pin_valid(const char* targetPIN){
    char tmp_buffer[10];

    get_string_prompt("\n Enter your pin: ", tmp_buffer, sizeof(tmp_buffer));

    if (strcmp(tmp_buffer, targetPIN) == 0) {
        return true;
    } else {
        return false;
    }
}

bool is_valid_receiver(int referrence, int target){
    if (referrence != target || referrence <= -1){
        return false;
    }
    return true;
}