#!/bin/bash
clear
cmake -S . -B build -G Ninja
cd build/
ctest \
 --test-output-size-passed 2048 \
 --no-compress-output \
 --output-on-failure \
 -D Experimental \
 -T MemCheck \
 -j 6

rm -rf Testing