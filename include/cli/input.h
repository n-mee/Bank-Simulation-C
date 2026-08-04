#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

bool get_prompt_string(const char* prompt, char* out_n, size_t size);
int get_prompt_int(const char* prompt);
double get_prompt_double(const char* prompt);
bool get_yn_prompt(const char* prompt, bool* out_c);

#endif