#include <stdio.h>
#include <string.h>
#include "../include/utils/validators.h"
#include "../include/utils/input_parser.h"
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

void set_email_notif(Account *session, bool enabled) {
    if (session->preference.email_notif == enabled) {
        printf("Your email notifications are already %s.\n", enabled ? "ENABLED" : "DISABLED");
        return;
    }
    session->preference.email_notif = enabled;
    printf("\nEmail notifications are now %s.\n", enabled ? "ENABLED" : "DISABLED");
}

void set_push_notif(Account *session, bool enabled) {
    if (session->preference.push_notif == enabled) {
        printf("Your push notifications are already %s.\n", enabled ? "ENABLED" : "DISABLED");
        return;
    }
    session->preference.push_notif = enabled;
    printf("\nPush notifications are now %s.\n", enabled ? "ENABLED" : "DISABLED");
}

void set_low_bal_notif(Account *session, bool enabled) {
    if (session->preference.low_balance_alert == enabled) {
        printf("Your low balance alert notifications are already %s.\n", enabled ? "ENABLED" : "DISABLED");
        return;
    }
    session->preference.low_balance_alert = enabled;
    printf("\nLow balance alert notifications are now %s.\n", enabled ? "ENABLED" : "DISABLED");
}

void set_large_txn_notif(Account *session, bool enabled) {
    if (session->preference.large_transaction_alert == enabled) {
        printf("Your large transactions alert notifications are already %s.\n", enabled ? "ENABLED" : "DISABLED");
        return;
    }
    session->preference.large_transaction_alert = enabled;
    printf("\nLarge transactions are notifications are now %s.\n", enabled ? "ENABLED" : "DISABLED");
}

void set_acc_frozen(Account *session) {
    if (get_yes_no_prompt("\nDo you wanna FREEZE your account? (yes/no): ") != true) {
        printf("Returning...\n");
        return;
    }

    if (session->controls.status == ACCOUNT_CLOSED) {
        printf("Cannot FREEZE an already CLOSED account.\n");
        return;
    }

    if (session->controls.status == ACCOUNT_FROZEN) {
        printf("Your account is already frozen.\n");
        return;
    }

    session->controls.status = ACCOUNT_FROZEN;
    printf("Successfully freezed the account.\n");
}

void set_acc_active(Account *session) {
    if (get_yes_no_prompt("\nDo you wanna Re-Activate your account? (yes/no): ") != true) {
        printf("Returning...\n");
        return;
    }

    if (session->controls.status == ACCOUNT_ACTIVE) {
        printf("Your account is already ACTIVE.\n");
        return;
    }

    session->controls.status = ACCOUNT_ACTIVE;
    printf("Successfully re-activated the account.\n");
}

void set_acc_closed(Account *session) {
    if (get_yes_no_prompt("\nDo you wanna CLOSE your account? (yes/no): ") != true) {
        printf("Returning...\n");
        return;
    }

    if (session->controls.status == ACCOUNT_CLOSED) {
        printf("Your account is already CLOSED.\n");
        return;
    }

    session->controls.status = ACCOUNT_CLOSED;
    printf("Successfully CLOSED the account.\n");
}

void set_daily_limit(Account *session, double new_limit) {
    if (!is_valid_limit(&new_limit)) {
        printf("Limit should only be between 10,000-50,000. Try again..\n");
        return;
    }
    session->controls.daily_limit = new_limit;
    printf("Sucessfully set a new limit: %.2f.\n", session->controls.daily_limit);
}