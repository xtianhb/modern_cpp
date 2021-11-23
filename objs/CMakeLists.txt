cmake_minimum_required(VERSION 3.0.0)
project(objs VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(objs.bin main.cpp objs.cpp)

target_include_directories(objs.bin PUBLIC ./)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
