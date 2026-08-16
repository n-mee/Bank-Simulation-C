#ifndef CONSTANTS_H
#define CONSTANTS_H

// limit sizes for validation

#define PIN_LENGTH 4
#define EMAIL_LEN 12
#define USERNAME_LEN 3

// operation flags

typedef enum {
    UPDATE_PIN,
    UPDATE_EMAIL,
    UPDATE_USERNAME
} AccountOperationType;

typedef enum {
    ENABLE_EMAIL_NOTIF,
    ENABLE_PUSH_NOTIF,
    ENABLE_LARGE_TXN_NOTIF,
    ENABLE_LOW_BAL_NOTIF
} AccountNotificationsType;

typedef enum {
    SET_STATE_FREEZE,
    SET_STATE_ACTIVATE,
    SET_STATE_CLOSED,
    SET_LIMIT_UPDATE
} AccountStateOperationType;

typedef enum {
    WITHDRAW,
    DEPOSIT,
    TRANSFER
} TransactionType;

#endif