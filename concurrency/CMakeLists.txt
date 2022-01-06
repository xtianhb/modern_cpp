cmake_minimum_required(VERSION 3.0.0)

set(TARGET concurrency.bin)

project(${TARGET} VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

set(SOURCES main.cpp)
list(APPEND SOURCES promise_future.cpp async.cpp threads.cpp threads_funs.cpp sharingdata.cpp  )

add_executable(${TARGET} ${SOURCES} )

target_include_directories(${TARGET} PUBLIC ./)
target_link_libraries(${TARGET} Threads::Threads)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(${TARGET} PRIVATE -Wno-unused-variable -Wall )
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
