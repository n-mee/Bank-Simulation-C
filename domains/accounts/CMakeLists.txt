add_library(accounts SHARED src/account_service.cpp)

target_include_directories(accounts PUBLIC include)

target_link_libraries(accounts PRIVATE api utils)