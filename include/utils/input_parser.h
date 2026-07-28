#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

/**
 * @brief Prompts the user and safely parses a string input to an integer
 * @param prompt Message displayed on the terminal
 * @return Convered integer value
 */
int get_int_prompt(const char* prompt);

/**
 * @brief Prompts the user and safely parses a string input to an integer
 * @param prompt Message displayed on the terminal
 * @return Converted double value
 */
double get_decimal_prompt(const char* prompt);

/**
 * @brief Safely reads a string input and trims the trailing newline char
 * @param prompt Message displayed on the terminal
 * @param output_buffer Pointer to the character array where string will be stored in
 * @param buffer_size The max size of the output to prevent overflow
 */
void get_string_prompt(const char* prompt, char* output_buffer, int buffer_size);

#endif