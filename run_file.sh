#!/bin/sh
clear
cmake -S . -B build
cmake --build build
cd build
./mainApp
