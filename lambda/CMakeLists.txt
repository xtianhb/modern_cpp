cmake_minimum_required(VERSION 3.0.0)
project(lambda VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(lambda.bin main.cpp lambda.cpp funobj.cpp capture.cpp)

target_include_directories(lambda.bin PUBLIC ./)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(lambda.bin PRIVATE -Wno-unused-variable -Wall )
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
