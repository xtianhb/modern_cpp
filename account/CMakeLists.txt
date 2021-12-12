cmake_minimum_required(VERSION 3.0.0)
project(account VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(account.bin main.cpp account.cpp checking.cpp savings.cpp transaction.cpp)

target_include_directories(account.bin PUBLIC ./)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
