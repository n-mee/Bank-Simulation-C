// headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// function prototypes
int get_prompt_choice();

int main(void) {

    int choice = get_prompt_choice();
    printf("You typed: %d!\n", choice);

    return 0;
}

int get_prompt_choice() {
    // declares the buffer and the actual variable for choice.
    char buffer[100];
    int choice;

    // the prompt will keep repeating until the user enters a proper number.
    while(true){
        // asks for prompt
        printf("Enter a number: ");
            // the main function that will catch the user's initial prompt as string which is named as "buffer"
            if (fgets(buffer, sizeof(buffer), stdin) != NULL){
                // converts that string into a integer based on the return value of the function.
                if (sscanf(buffer, "%d", &choice) == 1){
                return choice;
            }
        }
        // else this prompt will print showing what the user typed and then repeats the loop.
        printf("You typed a non-integer value: %s", buffer);
    }
}