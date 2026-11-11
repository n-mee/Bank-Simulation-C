add_library(utils SHARED
    src/input.cpp
    src/system_logger.cpp
    src/validators.cpp
    src/value_parser.cpp    
)

target_include_directories(utils PUBLIC include)

target_link_libraries(utils PRIVATE api storage)