cmake_minimum_required(VERSION 3.22)
set(this testfile)
project(${this} C CXX)
include(CTest)
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
## order of libs is important. prioritize libs that are independent of others. change the order of libs if there're cyclic depentdent libs

option(ENABLE_COVERAGE "Enable coverage" ON)
if(ENABLE_COVERAGE)
  if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    message(STATUS "Coverage analysis with gcov enabled") 
    target_compile_options(${this}
      PUBLIC
        -fprofile-arcs -ftest-coverage -g
      )
    target_link_libraries(${this}
      PUBLIC
        gcov
      )
  else()
    message(WARNING "Coverage not supported for this compiler")
  endif()
endif()

add_test(
    NAME ${this}
    COMMAND ./${this} --gtest_filter=InterfaceTest.set_total_value)
    
add_test(
    NAME ${this}-make-new-order
    COMMAND bash -c "echo -ne \"1\ndivine rapier\n1\nn\nbao\ntma\n911\" | ./${this} --gtest_filter=InterfaceTest.make_new_order")

add_test(
    NAME ${this}-make-new-order2
    COMMAND bash -c "echo -ne \"1\ndivine rapier\n1\nn\nhoang\ntma\n911\" | ./${this} --gtest_filter=InterfaceTest.make_new_order2")

add_test(
    NAME ${this}-make-new-order3
    COMMAND bash -c "echo -ne \"1\ndivine rapier\n1\nn\nnam\ntma\n911\" | ./${this} --gtest_filter=InterfaceTest.make_new_order3")

add_test(
    NAME ${this}-make-new-order4
    COMMAND bash -c "echo -ne \"1\ndivine rapier\n1\nn\ntien\ntma\n911\" | ./${this} --gtest_filter=InterfaceTest.make_new_order4")

add_test(
    NAME ${this}-make-new-order5
    COMMAND bash -c "echo -ne \"1\ndivine rapier\n1\nn\ntuyen\ntma\n911\" | ./${this} --gtest_filter=InterfaceTest.make_new_order5")
