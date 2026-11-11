cmake_minimum_required(VERSION 4.0)
project(BankIt VERSION 0.2 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(api)

add_subdirectory(domains/utils)
add_subdirectory(domains/auth)
add_subdirectory(domains/storage)
add_subdirectory(domains/ledger)

add_subdirectory(apps/bank_cli)