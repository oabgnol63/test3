#!/bin/bash
clear
cmake -S . -B build -G Ninja
cd build/
ctest \
 --test-output-size-passed 2048 \
 --test-ouput-size-failed 2048 \
 --output-on-failure \
 -D Experimental \
 -D MemoryCheck \
 -j 6

rm -rf Testing