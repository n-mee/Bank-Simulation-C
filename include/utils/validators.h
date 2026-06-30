#ifndef VALIDATORS_H
#define VALIDATORS_H

#include <stdbool.h>
bool is_valid_bal(double amt);
bool is_valid_pin(const char* target_pin, const char* input_pin);
bool is_valid_length_input(const char* target);
bool is_valid_id(int referrence, int target);

#endif