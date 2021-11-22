cmake_minimum_required(VERSION 3.0.0)
project(memory VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(memory.bin main.cpp memory.cpp)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(memory.bin PRIVATE -Wall -Wextra -Wpedantic -Wno-unused-variable)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
