cmake_minimum_required(VERSION 3.16..3.22)
set(this testfile)
project(${this} C CXX)
set(CMAKE_CXX_STANDARD 17)
find_package(GTest REQUIRED)
message("GTEST_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}")
set(GMOCK_LIBRARIES /usr/lib/libgmock.a /usr/lib/libgmock_main.a)
add_executable(${this} test.cc)
target_link_libraries(${this} PUBLIC
    ${GTEST_LIBRARIES} 
    ${GMOCK_LIBRARIES} 
    customer
    order
    item
    interface)
## order of lib is important. prioritize lib that independent of others.

add_test(
    NAME ${this}
    COMMAND ${this}
)
