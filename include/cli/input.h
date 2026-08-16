#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

/**
 * @brief handles the string input for user interface
 * @param prompt custom message reference
 * @param out_n pointer variable reference to put value into
 * @param size size of pointer variable reference
 * @return true if operation succeeds, false if not
 */
bool get_prompt_string(const char* prompt, char* out_n, size_t size);

/**
 * @brief gets the string input and converts into integer
 * @param prompt custom message reference
 * @return integer value for a variable
 */
int get_prompt_int(const char* prompt);

/**
 * @brief gets the string input and converts it into double long. (mostly used in balance)
 * @param prompt custom message pointer reference
 * @return double long value on a variable
 */
long long get_prompt_amount(const char* prompt);

/**
 * @brief gets the input of 'y' and 'n' and converts it into boolean value
 * @param prompt custom message reference
 * @param out_c pointer reference for a boolean variabe
 * @return true if the operation succeeds, false if not
 */
bool get_yn_prompt(const char* prompt, bool* out_c);

#endif