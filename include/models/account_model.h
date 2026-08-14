#ifndef ACCOUNT_MODEL_H
#define ACCOUNT_MODEL_H

/**
 * @brief Account database model used in the database
 * 
 * @note: Nothing much to do here, it's just the model of
 *        an account you see being accessed in the database
*/

#include "common/constants.h"

typedef struct {
    char name[51];
    char username[21];
    char email[71];
    char pin[PIN_LENGTH + 1];
} ProfileSettings;

typedef struct {
    bool email_notif;
    bool push_notif;
    bool low_balance_alert;
    bool large_transaction_alert;
} PreferenceSettings;

typedef enum {
    ACCOUNT_ACTIVE,
    ACCOUNT_FROZEN,
    ACCOUNT_CLOSED
} AccountStatus;

typedef struct {
    AccountStatus status;
    long long daily_limit;
} CardControls;

typedef struct {
    int accID;
    long long bal;

    ProfileSettings profile;
    PreferenceSettings preference;
    CardControls controls;
} Account;

#endif