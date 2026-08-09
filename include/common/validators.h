#ifndef VALIDATORS_H
#define VALIDATORS_H

// Dependency Header
#include <stdbool.h>
#include <string.h>


/**
 * NOTE: There is a duplicated function of valid pin
 *       One has its own scope input
 * 
 * TODO: Fix the duplication and only keep one pin validation
 *       function, then refactor the codebase.
 */



/**
 * @brief Validates the balance by checking if it's greater than 0
 * @param amt Amount that is being evaluated
 * @return True if balance is positive, False if it's not
 */
bool is_valid_bal(double amt);

/**
 * @brief Validates pin by comparing two string values
 * @param target_pin Pointer pin to authoritative PIN to match against
 * @param input_pin Pointer pin to the user-supplied PIN being evaluated
 * @return True if it matches, False if not
 */
bool is_valid_pin(const char* target_pin, const char* input_pin);

/**
 * @brief Checks the length of a string whether it matches or exceeds length constraints
 * @param target Target string to be validated
 * @param limit_len Comparator size for limit checking
 * @return True if it passes the validation, False otherwise
 */
bool is_valid_length_input(const char* target, int limit_len);

/**
 * @brief Validates ID by comparing it against a reference value
 * @param referrence The Master ID to comapre against
 * @param target System ID to be evaluated
 * @return True if both ID matches, False if not
 */
bool is_valid_id(int referrence, int target);
bool is_valid_pin_length(const char* target_pin);
bool is_valid_limit(const double* target);

#endif