#!/bin/bash
clear
cmake -S . -B build
cmake --build build
cd build/test
echo -ne "1\ndivine rapier\n1\nn\nbao\ntma\n911" | ./testfile --gtest_filter=InterfaceTest.make_new_order
echo -ne "1\ndivine rapier\n1\nn\nbao\ntma\n911" | ./testfile --gtest_filter=InterfaceTest.make_new_order2
echo -ne "1\ndivine rapier\n1\nn\nbao\ntma\n911" | ./testfile --gtest_filter=InterfaceTest.make_new_order3
echo -ne "1\ndivine rapier\n1\nn\nbao\ntma\n911" | ./testfile --gtest_filter=InterfaceTest.make_new_order4
echo -ne "1\ndivine rapier\n1\nn\nbao\ntma\n911" | ./testfile --gtest_filter=InterfaceTest.make_new_order5

