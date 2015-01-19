#!/bin/sh

g++ -std=c++11 -O2 -Wall -Wextra -Wconversion -Wl,--stack=67108864 -static -o benchmark benchmark.cpp
