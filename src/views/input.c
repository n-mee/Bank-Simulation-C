#include "input.h"
#include "input_parser.h"

// Prompts the user to enter the target id.
int get_receiver_id_input(){
    return get_int_prompt("Enter the reciever's ID: ");
}

// Prompts the user to get the amount of money.
double get_amount(){
    return get_decimal_prompt("Enter the amount: ");
}