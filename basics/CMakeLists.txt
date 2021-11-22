cmake_minimum_required(VERSION 3.0.0)
project(basics VERSION 0.1.0)

include_directories("./")

include(CTest)
enable_testing()

add_executable(basic main.cpp basic.cpp assignments.cpp)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(basic  PRIVATE -Wall -Wextra -Wpedantic -Wno-unused-variable)

endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
