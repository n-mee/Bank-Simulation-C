#include <stdbool.h>
#include <string.h>
#include "cli/input.h"
#include "common/validators.h"
#include "services/auth_service.h"
#include "repositories/account_repository.h"

static AuthStatus set_default_values(Account* target) {
    if (!target) return AUTH_ERR_SESSION_NULL;

    target->preference.email_notif = false;
    target->preference.push_notif = false;
    target->preference.large_transaction_alert = false;
    target->preference.low_balance_alert = false;
    target->controls.status = ACCOUNT_ACTIVE;
    target->controls.daily_limit = 10000.00;

    return AUTH_OPERATION_SUCCESS;
}

bool service_account_exists(BankDatabase *db, int id) {
    if (!db) return false;

    int find_id = db_find_identity(db, id);
    if (find_id == -1) return false;
    
    return true;
}

AuthStatus register_account (BankDatabase* db, Account raw_data, int* acc_id) {
    if (!db || !acc_id) return AUTH_ERR_SESSION_NULL;

    if (!is_valid_pin_length(raw_data.profile.pin)) {
        return AUTH_ERR_BAD_PIN;
    }

    AuthStatus init_account = set_default_values(&raw_data);
    if (init_account != AUTH_OPERATION_SUCCESS) return init_account;

    int new_id = db_account_creation(db, raw_data);
    if (new_id == -1) return AUTH_ERR_DB_FULL;

    *acc_id = new_id;
    return AUTH_REGISTRATION_SUCCESS;
}

AuthStatus authenticate_account(BankDatabase* db, int id, const char* pin, Account** session) {
    if (!db || !pin || !session) return AUTH_ERR_SESSION_NULL;

    int find_id = db_find_identity(db, id);
    if (find_id == -1) return AUTH_ERR_NOT_FOUND;

    if (db->records[find_id].controls.status == ACCOUNT_CLOSED) {
        return AUTH_ERR_CLOSED;
    }

    if (strncmp(pin, db->records[find_id].profile.pin, PIN_LENGTH) != 0) {
        return AUTH_ERR_BAD_PIN;
    }

    *session = &db->records[find_id];
    return AUTH_LOGIN_SUCCESS;
}