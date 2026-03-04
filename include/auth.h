#ifndef AUTH_H
#define AUTH_H

#include <stdbool.h>
bool is_pin_valid(int targetPIN);
bool is_valid_receiver(int referrence, int target);
bool is_valid_bal(double amt);

#endif