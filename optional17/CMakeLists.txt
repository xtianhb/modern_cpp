cmake_minimum_required(VERSION 3.0.0)
project(optional17 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET optional17.bin )
include(CTest)
enable_testing()

set(SOURCES main.cpp)
list(APPEND SOURCES optional.cpp variant.cpp string_view.cpp any.cpp filesystem.cpp parallel.cpp )

add_executable( ${TARGET} ${SOURCES} )

target_link_libraries(${TARGET} tbb)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
