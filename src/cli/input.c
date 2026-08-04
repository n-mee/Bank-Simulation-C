#include <string.h>
#include <stdio.h>
#include "cli/display_error_msg.h"
#include "common/exit_status.h"
#include "cli/input.h"
#include "common/value_parser.h"

static bool read_line(const char* prompt, char* buf, size_t size) {
    printf("%s", prompt);
    if (fgets(buf, (int)size, stdin) == NULL) {
        buf[0] = '\0';
        return false;
    }
    buf[strcspn(buf, "\n")] = '\0';
    return true;
}

void get_pin(char* PIN) {
    get_string_prompt("Enter your PIN: ", PIN, sizeof(PIN));
}

bool get_prompt_string(const char* prompt, char* out_str, size_t size) {
    char msg[128];

    for(;;) {
        if(!read_line(prompt, msg, sizeof(msg))) return false;

        ParsedStringResult status = string_parser(msg, out_str, size);
        if (status == PARSED_STRING_SUCCESS) return true;

        invalid_string_value(status);
    }
}

int get_prompt_int(const char* prompt) {
    char msg[128];
    int value;

    for(;;){
        if (read_line(prompt, msg, sizeof(msg))) return -1;

        ParseExitResult status = int_parser(msg, &value);
        if (status == PARSE_SUCCESS) return value;

        invalid_integer_value(status);
    }
}

double get_prompt_double(const char* prompt) {
    char msg[128];
    double value;

    for(;;) {
        if (read_line(prompt, msg, sizeof(msg))) return -1;

        ParseExitResult status = double_parser(msg, &value);
        if (status == PARSE_SUCCESS) return value;

        invalid_double_input(status);
    }
}

bool get_yn_prompt(const char* prompt, bool* out_c) {
    char msg[128];

    for(;;) {
        if (read_line(prompt, msg, sizeof(msg))) return false;

        YesNoResult status = yn_parser(msg, out_c);
        if (status == YN_SUCCESS) return true;

        invalid_bool_value(status);
    }
}