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

void invalid_string_value(ParsedStringResult status) {
    switch (status) {
        case ERR_EMPTY_STRING: printf("[!] ERROR: Input cannot be empty.\n"); break;
        case ERR_EXCEEDED_MAX_SIZE: printf("[!] ERROR: Text exceeds memory limits.\n"); break;
        case ERR_STRING_NULL_PTR: printf("[!] ERROR: String referrence is pointed to NULL.\n"); break;
        default: break;
    }
}

void invalid_pin_length() {
    printf("[!] ERROR: Invalid PIN length.\n");
}