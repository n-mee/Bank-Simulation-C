#include <stdio.h>
#include <stdbool.h>
#include "utils/input_parser.h"
#include "data/static_user.h"
#include "views/main_menu.h"
#include "views/displays.h"
#include "controllers/handler.h"

int main(void) {

    User a1 = {101, "Cassian", 1000.00, 2007};
    User a2 = {102, "Scythe", 00.00, 1501};
    bool running = true;

    header_menu();

    while (running) {
        choice_menu();
        int choice = get_int_prompt("\n Enter Selection: ");

        switch (choice) {
            case 1:
                handle_withdraw_request(&a1);
                break;
            case 2:
                handle_deposit_request(&a1);
                break;
            case 3:
                handle_transfer_request(&a1, &a2);
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