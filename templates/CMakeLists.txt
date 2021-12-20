cmake_minimum_required(VERSION 3.0.0)
project(file_io VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(templates.bin main.cpp templates.cpp integer.cpp variadic.cpp classtemp.cpp aliases.cpp)
target_include_directories(templates.bin PUBLIC ./)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(templates.bin PRIVATE -Wno-unused-variable -Wall -Wno-unknown-pragmas --std=c++17 )
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
