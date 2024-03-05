cmake_minimum_required(VERSION 3.10)
project(oop_lab_03)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_compile_options(-pedantic -Wall)

# set(TEST_EXE tests/test.cpp)
set(SOURCE_EXE src/main.cpp)
set(SOURCE_LIB src/figure.cpp)
set(SOURCE_LIB src/rectangle.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(main src/main.cpp src/figure.cpp src/rectangle.cpp src/rhombus.cpp src/point.cpp src/trapezoid.cpp)
add_executable(test tests/test.cpp src/figure.cpp src/rectangle.cpp src/rhombus.cpp src/point.cpp src/trapezoid.cpp)

target_link_libraries(test  ${GTEST_LIBRARIES})