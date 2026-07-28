#include <string.h>
#include "../include/views/displays.h"
#include "../include/core/account_actions.h"


void account_update_pin(Account *session, const char* new_pin) {
    // Replaces the sessions account pin with the param pin
    strncpy(session->pin, new_pin, sizeof(session->pin) - 1);
    // Assigns a null terminator at the end of the string
    session->pin[sizeof(session->pin) - 1] = '\0';
}

void account_update_name(Account *session, const char* new_name) {
    // Replaces the sessions account name with the param name
    strncpy(session->name, new_name, sizeof(session->name) - 1);
    // Assigns a null terminator at the end of the string
    session->name[sizeof(session->name) - 1] = '\0';
}