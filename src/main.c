#include <stdio.h>
#include <stdbool.h>
#include "utils/input_parser.h"
#include "data/static_user.h"
#include "views/main_menu.h"
#include "views/displays.h"
#include "controllers/handler.h"

int main(void) {

    Account person1 = {101, 1000.00, "0123", "Black Scythe"};
    Account person2 = {102, 00.00, "2007", "Ryu Min"};
    bool running = true;

    while (running) {
        header_menu();
        choice_menu();
        int choice = get_int_prompt("\n Enter Selection: ");

        switch (choice) {
            case 1:
                handle_withdraw_request(&person1);
                break;
            case 2:
                handle_deposit_request(&person1);
                break;
            case 3:
                handle_transfer_request(&person1, &person2);
                break;
            case 0:
                display_farewell_msg();
                running = false;
                break;
            default:
                display_invalid_selection_msg();
        }
    }


    
    return 0;
}