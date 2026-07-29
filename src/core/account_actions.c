#include <string.h>
#include "../include/views/displays.h"
#include "../include/core/account_actions.h"


void account_update_pin(Account *session, const char* new_pin) {
    // Replaces the sessions account pin with the param pin
    strncpy(session->profile.pin, new_pin, sizeof(session->profile.pin) - 1);
    // Assigns a null terminator at the end of the string
    session->profile.pin[sizeof(session->profile.pin) - 1] = '\0';
}

void account_update_username(Account *session, const char* new_name) {
    // Replaces the sessions account name with the param name
    strncpy(session->profile.username, new_name, sizeof(session->profile.username) - 1);
    // Assigns a null terminator at the end of the string
    session->profile.username[sizeof(session->profile.username) - 1] = '\0';
}

void account_update_email(Account *session, const char* new_email) {
    // Replaces the sessions account name with the param name
    strncpy(session->profile.email, new_email, sizeof(session->profile.email) - 1);
    // Assigns a null terminator at the end of the string
    session->profile.email[sizeof(session->profile.email) - 1] = '\0';
}