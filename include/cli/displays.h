#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>

typedef enum {
    MSG_EXIT_TO_MENU,
    MSG_EXIT_SYS,
    MSG_COUNT
} SystemMessageID;

static inline void show_system_msg(SystemMessageID id) {
        const char* const SYS_MESSAGES[] = {
        [MSG_EXIT_TO_MENU] = "[-] Exiting to Menu..",
        [MSG_EXIT_SYS] = "[-] System is exiting..."
    };

    if (id >= 0 && id < MSG_COUNT) {
        printf("%s\n", SYS_MESSAGES[id]);
    }
}

#endif