#include <string.h>
#include <stdio.h>
#include "cli/display_error_msg.h"
#include "common/exit_status.h"
#include "cli/input.h"
#include "common/value_parser.h"

static void read_line(const char* prompt, char* buf, size_t size) {
    printf("%s", prompt);
    if (fgets(buf, (int)size, stdin) == NULL) buf[0] = '\0';
    buf[strcspn(buf, "\n")] = '\0';
}

void get_pin(char* PIN) {
    get_string_prompt("Enter your PIN: ", PIN, sizeof(PIN));
}

int get_prompt_int(const char* prompt) {
    char msg[128];
    int value;

    for(;;){
        read_line(prompt, msg, sizeof(msg));

        ParseExitResult status = int_parser(msg, &value);
        if (status == PARSE_SUCCESS) return value;

        invalid_integer_value(status);
    }
}

double get_prompt_double(const char* prompt) {
    char msg[128];
    double value;

    for(;;) {
        read_line(prompt, msg, sizeof(msg));

        ParseExitResult status = double_parser(msg, &value);
        if (status == PARSE_SUCCESS) return value;

        invalid_double_input(status);
    }
}

bool get_yn_prompt(const char* prompt) {
    char msg[128];
    bool choice;

    for(;;) {
        read_line(prompt, msg, sizeof(msg));

        YesNoResult status = yn_parser(msg, &choice);
        if (status == YN_SUCCESS) return choice;

        invalid_bool_value(status);
    }
}