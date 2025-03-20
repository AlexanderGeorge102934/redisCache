#!/bin/bash

# Compile main.cpp
echo "Compiling main.cpp..."
g++ -std=c++17 -o main_output main.cpp redisCache.cpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation of main.cpp successful!"
    echo "Running main_output..."
    ./main_output
else
    echo "Compilation of main.cpp failed!"
    exit 1
fi

