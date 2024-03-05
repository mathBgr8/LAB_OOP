cmake_minimum_required(VERSION 3.10)

project(oop_lab_07)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_compile_options(-pedantic -Wall -g)

add_executable(main src/main.cpp src/npc.cpp src/knight.cpp src/druid.cpp src/elf.cpp)
add_executable(test tests/test.cpp src/npc.cpp src/knight.cpp src/druid.cpp src/elf.cpp)

target_link_libraries(test  ${GTEST_LIBRARIES})