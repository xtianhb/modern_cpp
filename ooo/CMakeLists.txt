cmake_minimum_required(VERSION 3.0.0)
project(goodies VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ooo.bin main.cpp ooo.cpp )

target_include_directories(ooo.bin PUBLIC ./)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(ooo.bin PRIVATE -Wno-unused-variable -Wall)
endif()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
