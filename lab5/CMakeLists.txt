cmake_minimum_required(VERSION 3.10)
project(oop_lab_05)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-pedantic -Wall -g ) # -DDEBUG

set(TEST_EXE tests/test.cpp)
set(SOURCE_EXE src/main.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(main src/main.cpp)
add_executable(test tests/test.cpp)

target_link_libraries(test  ${GTEST_LIBRARIES})