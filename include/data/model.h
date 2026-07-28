#ifndef MODEL_H
#define MODEL_H

/**
 * @brief Account database model used in the database
 * 
 * @note: Nothing much to do here, it's just the model of
 *        an account you see being accessed in the database
 * 
 * TODO:
 *      Apply Binary Search Tree (BST) for better data structure
 *      before implementing role privileges and other management
 *      account roles
 */
typedef struct {
    int accID;
    double bal;
    char pin[5];
    char name[50];
} Account;

#endif