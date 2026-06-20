#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "utils/input_parser.h"

// dynamic parsing prompt to get string to integer.
// used a constant char for dynamic string arguments.
int get_int_prompt(const char* prompt) {
    // declare buffer to be used in string.
    char buffer[100];
    int number;

    // used a loop to reiterate the prompt until the user returns an actual value.
    while (true){
        // refers to the parameter prompt for the function itself (e.g. get_int_prompt("Enter a number: ");).
        printf("%s", prompt);
        // checks if the value of buffer is not NULL.
        if (fgets(buffer, sizeof(buffer), stdin) != NULL){
            // proceeds to the tha parsing method using sscanf();
            if (sscanf(buffer, "%d", &number) == 1){
                // if it returns a value then the function returns the number.
                return number;
            }
        }
        // else, it just repeats the loob with an error.
        printf("[!] ERROR: Please enter valid number.\n");
    }
}

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
        printf("[!] ERROR: Please enter valid decimals only.\n");
    }
}

void get_string_prompt(const char* prompt, char* output_buffer, int buffer_size) {
    fseek(stdin, 0, SEEK_END);
    while (true) {
        printf("%s", prompt);
        if (fgets(output_buffer, buffer_size, stdin) != NULL) {
            output_buffer[strcspn(output_buffer, "\n")] = '\0';
            if (strlen(output_buffer) > 0) {
                return;
            }
        }
        printf("[!] ERROR: Input cannot be empty. Try again.\n");
    }
}