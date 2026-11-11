add_library(auth SHARED src/auth_service.cpp)

target_include_directories(auth PUBLIC include)

target_link_libraries(auth
    PRIVATE
        api
        utils
        storage
)