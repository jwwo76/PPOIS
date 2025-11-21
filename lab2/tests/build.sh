#!/bin/bash

cd "$(dirname "$0")"

# Find all .cpp files except in tests directory
CPP_FILES=$(find .. -name "*.cpp" -not -path "*/tests/*" | tr '\n' ' ')

# Compile test file with all source files
g++ -O0 -std=c++17 -fprofile-arcs -ftest-coverage \
    -I.. \
    test_main.cpp $CPP_FILES \
    -lgtest -lgtest_main -pthread \
    -o tests

