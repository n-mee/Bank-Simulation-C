#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include "common/exit_status.h"
#include <stdlib.h>
#include <stdbool.h>

ParseExitResult int_parser(const char* text, int* out_n);
ParseExitResult amount_parser(const char* text, long long* out_n);
YesNoResult yn_parser(const char* text, bool* out_v);
ParsedStringResult string_parser(const char* text, char* out_str, size_t size_limit);

#endif