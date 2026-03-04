#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int get_int_prompt(const char* prompt);
double get_double_prompt(const char* prompt);

int main(void) {

    int n = get_int_prompt("Enter a number: ");
    double x = get_double_prompt("Enter a decimal: ");
    printf("The number you entered is: %d.\n", n);
    printf("The decimal you entered was: %.2lf.\n", x);

    return 0;
}

int get_int_prompt(const char* prompt) {
    char buffer[100];
    int number;

    while (true){
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL){
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d", &number) == 1){
                return number;
            }
        }
        printf("[!] ERROR: Please enter valid number.\n");
    }
}

double get_double_prompt(const char* prompt) {
    char buffer[100];
    double n;

    while (true){
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL){
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%lf", &n) == 1.0) {
                return n;
            }
        }
        printf("[!] ERROR: Please enter valid numbers only.\n");
    }
}