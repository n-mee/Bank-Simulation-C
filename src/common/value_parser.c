#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cli/displays.h"
#include "common/value_parser.h"

// dynamic parsing prompt to get string to integer.
// used a constant char for dynamic string arguments.
// int get_int_prompt(const char* prompt) {
//     // declare buffer to be used in string.
//     char buffer[100];
//     int number;

//     // used a loop to reiterate the prompt until the user returns an actual value.
//     while (true){
//         // refers to the parameter prompt for the function itself (e.g. get_int_prompt("Enter a number: ");).
//         printf("%s", prompt);
//         // checks if the value of buffer is not NULL.
//         if (fgets(buffer, sizeof(buffer), stdin) != NULL){
//             // proceeds to the tha parsing method using sscanf();
//             if (sscanf(buffer, "%d", &number) == 1){
//                 // if it returns a value then the function returns the number.
//                 return number;
//             }
//         }
//         // else, it just repeats the loob with an error.
//         invalid_integer_input();
//     }
// }

// gets the decimal value with applied direct prompt for the argument
double get_decimal_prompt(const char* prompt){
    // declare buffer
    char buffer[100];
    double n;

    // initialize loop so we can keep prompting user.
    while (true) {
        // the actual prompt derived from the parameters of the function
        printf("%s", prompt);
        // initial data masked in buffer for parsing and will only proceed if the value is not garbage data
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // actual parsing where we convert buffer to the desired input.
            if (sscanf(buffer, "%lf", &n) == 1){
                // returns the value of the decimal and ends the loop.
                return n;
            }
        }
        // else we print this error msg and proceed to loop until the user enters the corresponding valid number.
        invalid_decimal_input();
    }
}

void get_string_prompt(const char* prompt, char* output_buffer, int buffer_size) {
    while (true) {
        printf("%s", prompt);
        if (fgets(output_buffer, buffer_size, stdin) != NULL) {
            if (strchr(output_buffer, '\n') == NULL) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF); 
            }
            output_buffer[strcspn(output_buffer, "\n")] = '\0';
            if (strlen(output_buffer) > 0) {
                return;
            }
        }
        empty_string_input();
    }
}

bool get_yes_no_prompt(const char* prompt) {
    char answer[10];
    while (true) {
        get_string_prompt(prompt, answer, sizeof(answer));

        for (int i = 0; answer[i]; i++) {
            answer[i] = tolower((unsigned char)answer[i]);
        }

        if (strcmp(answer, "yes") == 0 || strcmp (answer, "y") == 0) {
            return true;
        } else if (strcmp(answer, "no") == 0 || strcmp(answer, "n") == 0) {
            return false;
        }
        invalid_yn_choice();
    }
}

ParseExitResult int_parser(const char* text, int* out_n) {
    char* end = NULL;
    long value = strtol(text, &end, 10);

    if (end == text) return ERR_NULL_PTR;

    while(*end == ' ' || *end == '\t' || *end == '\n') end++;
    if(*end != '\0') return ERR_TRAILING_GARBAGE;

    *out_n = (int)value;
    return PARSE_SUCCESS;
}

ParseExitResult double_parser(const char* text, double* out_n) {
    char* end = NULL;
    long value = strtod(text, &end);

    if (end == text) return ERR_NULL_PTR;

    while(*end == ' ' || *end == '\t' || *end == '\n') end++;
    if(*end != '\0') return ERR_TRAILING_GARBAGE;

    *out_n = (double)value;
    return PARSE_SUCCESS;
}

YesNoResult yn_parser(const char* text, bool* out_v) {
    char buffer[16];
    size_t buf_size = strlen(text);

    if (buf_size >= sizeof(buffer)) return ERR_INPUT_EXCEED_RANGE;

    for (size_t i = 0; i < buf_size; i++) buffer[i] = (char)tolower((unsigned char)text[i]);
    buffer[buf_size] = '\0';

    if (strcmp(buffer, "yes") == 0 || strcmp(buffer, "y") == 0) { *out_v = true; return YN_SUCCESS; }
    if (strcmp(buffer, "no") == 0 || strcmp(buffer, "n") == 0) { *out_v = false; return YN_SUCCESS; }
    return ERR_INVALID_INPUT;
}