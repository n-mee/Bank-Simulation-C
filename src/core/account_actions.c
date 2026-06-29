#include <string.h>
#include "../include/views/displays.h"
#include "../include/core/account_actions.h"

void account_update_pin(Account *session, const char* new_pin) {
    strncpy(session->pin, new_pin, sizeof(session->pin) - 1);
    session->pin[sizeof(session->pin) - 1] = '\0';
}

void account_update_name(Account *session, const char* new_name) {
    strncpy(session->name, new_name, sizeof(session->name) - 1);
    session->name[sizeof(session->name) - 1] = '\0';
}