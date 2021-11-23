cmake_minimum_required(VERSION 3.0.0)
project(basics VERSION 0.1.0)

include_directories("./")

include(CTest)
enable_testing()

add_executable(basics.bin main.cpp basics.cpp assignments.cpp)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(basics.bin PRIVATE -Wall -Wextra -Wpedantic -Wno-unused-variable)
endif()

target_include_directories(basics.bin PUBLIC ./)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
