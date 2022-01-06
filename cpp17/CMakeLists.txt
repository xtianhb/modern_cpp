cmake_minimum_required(VERSION 3.0.0)
project(cpp17 VERSION 0.1.0)



include(CTest)
enable_testing()

set(SOURCES mandatory_copy_elision.cpp evaluation_order.cpp structured_bindings.cpp )
list(APPEND SOURCES constexpr_lambda.cpp noexcept.cpp if_switch.cpp attributes.cpp )
list(APPEND SOURCES feature_macros.cpp nested_namespaces.cpp)
list(APPEND SOURCES inline/a.cpp inline/b.cpp inline/inline.cpp )

set(TARGET cpp17.bin)

add_executable(${TARGET} main.cpp ${SOURCES})

target_compile_features( ${TARGET} PUBLIC cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
