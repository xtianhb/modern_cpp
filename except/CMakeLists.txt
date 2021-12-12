cmake_minimum_required(VERSION 3.0.0)
project(except VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(except.bin main.cpp except.cpp )
target_include_directories(except.bin PUBLIC ./)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
