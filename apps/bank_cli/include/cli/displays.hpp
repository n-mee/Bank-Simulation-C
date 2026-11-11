#pragma once

#include <cstdio>

// flags for switching standard system msg
typedef enum {
    MSG_EXIT_TO_MENU,
    MSG_EXIT_SYS,
    // counts the overall flags
    MSG_COUNT
} SystemMessageID;

/**
 * @brief inline system message for standard system message
 * @param id reference flag for dynamic message switching
 */
inline void show_system_msg(SystemMessageID id) {
        static constexpr char* const SYS_MESSAGES[MSG_COUNT] = {
        "[-] Exiting to Menu..",
        "[-] System is exiting..."
    };

    if (id >= 0 && id < MSG_COUNT) {
        std::printf("%s\n", SYS_MESSAGES[id]);
    }
}