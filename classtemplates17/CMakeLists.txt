cmake_minimum_required(VERSION 3.0.0)
project(cpp17 VERSION 0.1.0)



include(CTest)
enable_testing()

set(SOURCES fold_expressions.cpp ctad.cpp ifconstexpr.cpp traits_suffixes.cpp)


set(TARGET temp17.bin)

add_executable(${TARGET} main.cpp ${SOURCES})

target_compile_features( ${TARGET} PUBLIC cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
