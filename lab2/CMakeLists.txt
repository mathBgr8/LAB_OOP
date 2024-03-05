cmake_minimum_required(VERSION 3.10)
project(oop_lab_02)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_EXE tests/test.cpp)
set(SOURCE_EXE src/main.cpp)
set(SOURCE_LIB src/money.cpp)

find_package(GTest REQUIRED)
add_library(money STATIC ${SOURCE_LIB})
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(main ${SOURCE_EXE})
add_executable(test ${TEST_EXE})

target_link_libraries(main money)
target_link_libraries(test money ${GTEST_LIBRARIES})