cmake_minimum_required(VERSION 3.0.0)
project(opover VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(mem2.bin main.cpp mem2.cpp integer.cpp)

target_include_directories(mem2.bin PUBLIC ./)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(mem2.bin PRIVATE -Wno-unused-variable -Wall)
endif()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
