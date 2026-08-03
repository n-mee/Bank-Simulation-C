#include <stdio.h>
#include <string.h>
#include "common/validators.h"
#include "common/value_parser.h"
#include "cli/displays.h"
#include "services/account_service.h"


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
        email_notif_alr_on(enabled);
        return;
    }
    session->preference.email_notif = enabled;
    email_enable_msg(enabled);
}

void set_push_notif(Account *session, bool enabled) {
    if (session->preference.push_notif == enabled) {
        push_notif_alr_on(enabled);
        return;
    }
    session->preference.push_notif = enabled;
    push_enable_msg(enabled);
}

void set_low_bal_notif(Account *session, bool enabled) {
    if (session->preference.low_balance_alert == enabled) {
        lowbal_notif_alr_on(enabled);
        return;
    }
    session->preference.low_balance_alert = enabled;
    lowbal_enable_msg(enabled);
}

void set_large_txn_notif(Account *session, bool enabled) {
    if (session->preference.large_transaction_alert == enabled) {
        txn_notif_alr_on(enabled);
        return;
    }
    session->preference.large_transaction_alert = enabled;
    txn_enable_msg(enabled);
}

void set_acc_frozen(Account *session) {
    if (get_yes_no_prompt("\nDo you wanna FREEZE your account? (yes/no): ") != true) {
        printf("Returning...\n");
        return;
    }

    if (session->controls.status == ACCOUNT_CLOSED) {
        two_acc_status_inc();
        return;
    }

    if (session->controls.status == ACCOUNT_FROZEN) {
        acc_is_frozen();
        return;
    }

    session->controls.status = ACCOUNT_FROZEN;
    acc_freeze_success();
}

void set_acc_active(Account *session) {
    if (get_yes_no_prompt("\nDo you wanna Re-Activate your account? (yes/no): ") != true) {
        printf("Returning...\n");
        return;
    }

    if (session->controls.status == ACCOUNT_ACTIVE) {
        acc_is_active();
        return;
    }

    session->controls.status = ACCOUNT_ACTIVE;
    acc_reactivation_success();
}

void set_acc_closed(Account *session) {
    if (get_yes_no_prompt("\nDo you wanna CLOSE your account? (yes/no): ") != true) {
        printf("Returning...\n");
        return;
    }

    if (session->controls.status == ACCOUNT_CLOSED) {
        acc_is_closed();
        return;
    }

    session->controls.status = ACCOUNT_CLOSED;
    closed_acc_success();
}

void set_daily_limit(Account *session, double new_limit) {
    if (!is_valid_limit(&new_limit)) {
        limit_out_range();
        return;
    }
    session->controls.daily_limit = new_limit;
    acc_limit_success(session);
}