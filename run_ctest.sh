#!/bin/bash
clear
cmake -S . -B build
cd build/
ctest \
 --test-output-size-passed 2048 \
 --no-compress-output \
 -D Experimental \
 -T MemCheck \
 -j 6 
