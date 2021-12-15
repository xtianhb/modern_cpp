cmake_minimum_required(VERSION 3.0.0)
project(file_io VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(file_io.bin main.cpp file_io.cpp)
target_include_directories(file_io.bin PUBLIC ./)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(file_io.bin PRIVATE -Wno-unused-variable -Wall --std=c++17 )
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
