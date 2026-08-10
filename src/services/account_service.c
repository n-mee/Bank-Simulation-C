#include <stdbool.h>
#include <string.h>
#include "common/validators.h"
#include "common/value_parser.h"
#include "cli/input.h"
#include "cli/displays.h"
#include "cli/display_success_msg.h"
#include "services/account_service.h"


static bool account_update_credentials(Account *session, AccountOperationType type, const char* str) {
    if (!session || !str) return false;

    if (type == UPDATE_PIN) {
        if (strlen(str) != PIN_LENGTH || !is_valid_pin_length(str)) return false;
    } else if (type == UPDATE_USERNAME) {
        if (!is_valid_length_input(str, USERNAME_LEN)) return false;
    } else if (type == UPDATE_EMAIL) {
        if (!is_valid_length_input(str, EMAIL_LEN)) return false;
    }

    char* dest = NULL;
    size_t dest_size = 0;

    if (type == UPDATE_PIN) {
        dest = session->profile.pin;
        dest_size = sizeof(session->profile.pin);
    } else if (type == UPDATE_USERNAME) {
        dest = session->profile.username;
        dest_size = sizeof(session->profile.username);
    } else if (type == UPDATE_EMAIL) {
        dest = session->profile.email;
        dest_size = sizeof(session->profile.email);
    } else {
        return false;
    }

    if (strlen(str) >= dest_size) return false;
    strncpy(dest, str, dest_size - 1);
    dest[dest_size - 1] = '\0';

    return true;
}

Credentials change_credential_pipeline(Account* session, AccountOperationType type) {
    if (!session) return ERR_ACCOUNT_NULL;

    char current_pin[PIN_LENGTH + 1];
    char new_value[256];

    if (!get_prompt_string("\nEnter your PIN: ", current_pin, PIN_LENGTH)) return ERR_INVALID_PIN;
    if (!is_valid_pin(session->profile.pin, current_pin)) return ERR_MISMATCH_PIN;
    
    const char* prompt = NULL;
    size_t input_len = PIN_LENGTH;

    if (type == UPDATE_PIN) {
        prompt = "\nEnter your new PIN: ";
        input_len = PIN_LENGTH;
    } else if (type == UPDATE_EMAIL) {
        prompt = "\nEnter your new e-mail: ";
        input_len = EMAIL_LEN;
    } else if (type == UPDATE_USERNAME) {
        prompt = "\nEnter your new username: ";
        input_len = USERNAME_LEN;
    }

    if (!get_prompt_string(prompt, new_value, sizeof(new_value) - 1)) return ERR_INPUT_STR_ERROR;   
    if (!account_update_credentials(session, type, new_value)) return ERR_UPDATE_OPERATION_FAIL;

    account_operation_success(type);
    return OPERATION_SUCCESS;
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
    bool choice;
    get_yn_prompt("\nDo you wanna FREEZE your account? (yes/no): ", &choice);

    if (choice != true) {
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
    bool choice;
    get_yn_prompt("\nDo you wanna Re-Activate your account? (yes/no): ", &choice);

    if (choice != true) {
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
    bool choice;
    get_yn_prompt("\nDo you wanna CLOSE your account? (yes/no): ", &choice);
    
    if (choice != true) {
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

void update_daily_limit(Account *current_session) {
    bool choice;

    get_yn_prompt("\nDaily Limits should only be around 10,000 to 50,000.\nAre you sure you wanna continue? (yes/no): ", &choice);
    if (choice != true) {
        back_to_menu();
        return;
    }

    double new_limit = get_prompt_double("\nEnter new limit: ");
    set_daily_limit(current_session, new_limit);
}