cmake_minimum_required(VERSION 3.10)

project(oop_lab_06)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main src/main.cpp src/npc.cpp src/knight.cpp src/druid.cpp src/elf.cpp)