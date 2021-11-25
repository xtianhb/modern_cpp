cmake_minimum_required(VERSION 3.0.0)
project(mvsemantics VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(mvsemantics.bin main.cpp integer.cpp)

target_include_directories(mvsemantics.bin PUBLIC ./)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(mvsemantics.bin PRIVATE -Wall -Wextra -Wpedantic -Wno-unused-variable -fno-elide-constructors)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
