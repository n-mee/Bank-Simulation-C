add_library(ledger SHARED src/transaction_services.cpp src/account_service.cpp)

target_include_directories(ledger PUBLIC include)

target_link_libraries(ledger PRIVATE api utils auth storage)