#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int n = 1;
    int *nPtr = (int*) malloc(n * sizeof(int));

    *nPtr = 5;
    printf("Number: %d, was taken from HEAP memory.\n", *nPtr);
    printf("The memory address of that is: %p.\n", nPtr);

    if (nPtr == NULL) {
        printf("[!] ERROR: The pointer used was NULL. Exiting.\n");
        return 1;
    }

    free(nPtr);
    nPtr = NULL;

    if (nPtr == NULL) {
        printf("New memory addres: %p.\n", (void*)nPtr);
        printf("Oops, you had an out of bounds memory error!.\n");
        return 1;
    }

    return 0;
}