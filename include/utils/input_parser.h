#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

int get_int_prompt(const char* prompt);
double get_decimal_prompt(const char* prompt);
void get_string_prompt(const char* prompt, char* output_buffer, int buffer_size);

#endif