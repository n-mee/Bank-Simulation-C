#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include "common/exit_status.h"
#include <stdbool.h>

/**
 * @brief Safely reads a string input and trims the trailing newline char
 * @param prompt Message displayed on the terminal
 * @param output_buffer Pointer to the character array where string will be stored in
 * @param buffer_size The max size of the output to prevent overflow
 */
void get_string_prompt(const char* prompt, char* output_buffer, int buffer_size);

ParseExitResult int_parser(const char* text, int* out_n);
ParseExitResult double_parser(const char* text, double* out_n);
YesNoResult yn_parser(const char* text, bool* out_v);

#endif