#ifndef STATIC_USER_H
#define STATIC_USER_H

typedef struct {
    int accID;
    double bal;
    char pin[5];
    char name[50];
} Account;

#endif