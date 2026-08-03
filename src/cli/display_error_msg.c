#include "cli/display_error_msg.h"
#include <stdio.h>

void invalid_integer_value(ParseExitResult status) {
    switch(status) {
        case ERR_INVALID_INT: printf("[!] ERROR: Input does not start with a number.\n"); break;
        case ERR_NULL_PTR: printf("[!] ERROR: Input returned a Null pointer.\n"); break;
        case ERR_TRAILING_GARBAGE: printf("[!] ERROR: Found trailing garbage characters after a number.\n"); break;
        default: break;
    }
}

void invalid_double_input(ParseExitResult status) {
    switch (status) {
        case ERR_INVALID_DOUBLE: printf("[!] ERROR: Input does not start with a decimal.\n"); break;
        case ERR_NULL_PTR: printf("[!] ERROR: Input returned a Null pointer.\n"); break;
        case ERR_TRAILING_GARBAGE: printf("[!] ERROR: Found trailing garbage characters after a number.\n"); break;
        default: break;
    }
}

void invalid_bool_value(YesNoResult status) {
    switch (status) {
        case ERR_INVALID_INPUT: printf("[!] ERROR: Cannot detect a 'yes' or 'no' input.\n"); break;
        case ERR_INPUT_EXCEED_RANGE: printf("[!] ERROR: Text exceeds memory limits.\n"); break;
        default: break;
    }
}