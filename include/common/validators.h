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

/**
 * @brief validates pin length
 * @param target_pin pin reference to be evaluated
 * @return true if the pin matches the standard length, false if not
 */
bool is_valid_pin_length(const char* target_pin);

/**
 * @brief validates daily balance limit range
 * @param target reference for the daily limit
 * @return true if the balance is within range, false if its not
 */
bool is_valid_limit(const long long* target);

#endif