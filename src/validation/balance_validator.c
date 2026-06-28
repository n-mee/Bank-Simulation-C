#include <stdio.h>
#include <stdbool.h>
#include "auth/auth.h"
#include "views/displays.h"

// checks if the amount entered is valid and returns the according boolean values.
bool is_valid_bal(double amt) {
    if (amt <= 0) {
        error_bal_msg();
        return false;
    }
    return true;
}