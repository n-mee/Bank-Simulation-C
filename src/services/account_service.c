#include <stdbool.h>
#include <string.h>
#include "cli/input.h"
#include "common/validators.h"
#include "common/exit_status.h"
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

static AccountStateStatus update_account_status(Account* session, AccountStateOperationType type) {
    if (!session) return STATUS_OPERATION_ERR_SESSION_NULL;

    if (session->controls.status == ACCOUNT_CLOSED) return STATUS_OPERATION_ERR_CLOSE_INCOMPATIBLE;

    AccountStatus select_status;
    if (type == SET_STATE_FREEZE) select_status = ACCOUNT_FROZEN;
    else if (type == SET_STATE_ACTIVATE) select_status = ACCOUNT_ACTIVE;
    else if (type == SET_STATE_CLOSED) select_status = ACCOUNT_CLOSED;
    else return STATUS_OPERATION_ERR_SESSION_NULL;

    if (session->controls.status == select_status) return STATUS_OPERATION_WARN_ALREADY_SET;

    session->controls.status = select_status;
    return STATUS_OPERATION_SUCCESS;
}

static AccountStateStatus update_account_limit(Account* session, long long* new_limt) {
    if (!session) return STATUS_OPERATION_ERR_SESSION_NULL;

    if (!is_valid_limit(new_limt)) return STATUS_OPERATION_ERR_OUT_OF_RANGE;

    session->controls.daily_limit = *new_limt;
    return STATUS_OPERATION_SUCCESS;
}

Credentials change_credential_pipeline(Account* session, AccountOperationType type) {
    if (!session) return CRED_ERR_ACCOUNT_NULL;

    char current_pin[PIN_LENGTH + 1];
    char new_value[256];

    if (!get_prompt_string("\nEnter your PIN: ", current_pin, sizeof(current_pin))) return CRED_ERR_INVALID_PIN;
    if (!is_valid_pin(session->profile.pin, current_pin)) return CRED_ERR_MISMATCH_PIN;
    
    const char* prompt = NULL;

    if (type == UPDATE_PIN) {
        prompt = "\nEnter your new PIN: ";
    } else if (type == UPDATE_EMAIL) {
        prompt = "\nEnter your new e-mail: ";
    } else if (type == UPDATE_USERNAME) {
        prompt = "\nEnter your new username: ";
    }

    if (!get_prompt_string(prompt, new_value, sizeof(new_value) - 1)) return CRED_ERR_INPUT_STR_ERROR;   
    if (!account_update_credentials(session, type, new_value)) return CRED_ERR_UPDATE_OPERATION_FAIL;

    return CRED_OPERATION_SUCCESS;
}

NotificationsStatus account_notifications_pipeline (Account* session, AccountNotificationsType type, bool enabled) {
    if (!session) return NOTIF_ERR_SESSION_NULL;

    bool* target_field = NULL;

    if (type == ENABLE_EMAIL_NOTIF) target_field = &session->preference.email_notif;
    else if (type == ENABLE_PUSH_NOTIF) target_field = &session->preference.push_notif;
    else if (type == ENABLE_LARGE_TXN_NOTIF) target_field = &session->preference.large_transaction_alert;
    else if (type == ENABLE_LARGE_TXN_NOTIF) target_field = &session->preference.low_balance_alert;
    else return NOTIF_ERR_SESSION_NULL;

    if (*target_field == enabled) return NOTIF_WARN_ALREADY_SET;

    *target_field = enabled;

    return enabled ? NOTIF_SUCCESS_ENABLED : NOTIF_SUCCESS_DISABLED;
}

AccountStateStatus account_status_pipeline (Account* session, AccountStateOperationType type){
    if (!session) return STATUS_OPERATION_ERR_SESSION_NULL;

    bool confirm = false;
    const char* prompt = NULL;

    if (type == SET_STATE_FREEZE) prompt = "\nDo you wanna FREEZE your account? (yes/no): ";
    else if (type == SET_STATE_ACTIVATE) prompt = "\nDo you wanna RE-ACTIVATE your account? (yes/no): ";
    else if (type == SET_STATE_CLOSED) prompt = "\nDo you wanna CLOSE your account? (yes/no): ";
    else if (type == SET_LIMIT_UPDATE) prompt = "\nDaily Limits should ony be around 10k - 50k.\nDo you wanna continue? (yes/no): ";

    if (!get_yn_prompt(prompt, &confirm) || !confirm) return STATUS_OPERATION_ERR_SESSION_NULL;

    if (type == SET_LIMIT_UPDATE) {
        long long new_limit = get_prompt_amount("\nEnter new limt: ");
        return update_account_limit(session, &new_limit);
    }

    return update_account_status(session, type);
}
