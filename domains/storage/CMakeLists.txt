add_library(storage SHARED 
    src/account_repository.cpp
    src/file_operations.cpp
    src/file_utility.cpp
)

target_include_directories(storage PUBLIC include)

target_link_libraries(storage PRIVATE api)