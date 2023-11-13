#!/bin/bash
clear
cmake -S . -B build
#cmake --build build
cd build/
ctest -C Debug -j 10 --test-output-size-passed 2048  -D Experimental -T Coverage 
