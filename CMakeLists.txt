cmake_minimum_required(VERSION 3.22)
set(this mainApp)
project(${this} C CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(order order.h order.cpp)
add_library(customer customer.h customer.cpp)
add_library(item item.h item.cpp)
add_library(interface interface.h interface.cpp)
set(prlib order customer item interface)
add_executable(${this} main.cpp)
target_link_libraries(${this} PUBLIC ${prlib})   

##setting environment for ctest
find_program(MEMORYCHECK_COMMAND valgrind)
set(MEMORYCHECK_COMMAND_OPTIONS "-q --tool=memcheck --leak-check=full --show-reachable=no --num-callers=50 --trace-children=yes")
include(CTest)
enable_testing()
add_subdirectory(test)
