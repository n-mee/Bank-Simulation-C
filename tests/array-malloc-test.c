#include <stdio.h>
#include <stdlib.h>

int str_pars();

int main(void) {

    int arr_size = str_pars();

    if (arr_size <= 0) {
        printf("[!] ERROR: You can't put a negative number as a base size of your array.\n");
        return 1;
    }

    int *myArr = (int*) malloc(arr_size * sizeof(int));

    if (myArr == NULL) {
        printf("Memory Allocation Failed.\n");
        return 1;
    }

    for (int i = 0; i < arr_size; i++) {
        printf("Enter for index [%d]: ", i);

        if (scanf("%d", myArr + i) != 1){
            printf("Invalid Input.\n");
            break;
        }
    }

    for (int i = 0; i < arr_size; i++) {
        printf("Index[%d]: %d.\n", i, myArr[i]);
        printf("Address of this index is: %p.\n", &myArr[i]);
    }

    free(myArr);
    myArr = NULL;

    return 0;
}

int str_pars(){
    char buffer[100];
    int n;

    printf("Enter the size of you array: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%d", &n) == 1){
            return n;
        }
    }
    return -1;
}