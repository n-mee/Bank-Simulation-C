add_library(bank_lib SHARED
    main.cpp 
    src/cli/menus.cpp
    src/cli/display_error_msg.cpp
    src/cli/display_success_msg.cpp
    src/controllers/account_controller.cpp
    src/controllers/auth_controller.cpp
    src/controllers/transaction_controller.cpp
)

target_include_directories(bank_lib PUBLIC include)

target_link_libraries(bank_lib PRIVATE ledger api utils accounts auth storage)

add_executable(bank_cli 
    main.cpp 
    src/cli/menus.cpp
    src/cli/display_error_msg.cpp
    src/cli/display_success_msg.cpp
    src/controllers/account_controller.cpp
    src/controllers/auth_controller.cpp
    src/controllers/transaction_controller.cpp
)

target_link_libraries(bank_cli PRIVATE ledger api auth accounts storage utils bank_lib)