#!/bin/bash
rm -f *.o a.out output.txt
g++ -std=c++17 -o a.out $(ls *.cpp | grep -v comedy.cpp) -Wno-unused-variable -Wno-unused-function
./a.out > output.txt 2>&1
