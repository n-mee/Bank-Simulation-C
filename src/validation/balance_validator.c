#include <stdio.h>
#include <stdbool.h>
#include "auth.h"
#include "displays.h"

// checks if the amount entered is valid and returns the according boolean values.
bool is_valid_bal(double amt) {
    if (amt <= 0) {
        display_error_bal_msg();
        return false;
    }
    return true;
}