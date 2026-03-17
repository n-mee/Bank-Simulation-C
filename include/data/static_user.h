#ifndef STATIC_USER_H
#define STATIC_USER_H

typedef struct {
    int accID;
    char name[50];
    double bal;
    int pin;
} User;

#endif