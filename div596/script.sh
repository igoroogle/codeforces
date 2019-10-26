#!/bin/bash
rm -rf CMakelists.txt
touch -f CMakelists.txt
echo "cmake_minimum_required(VERSION 3.14)" | cat >> CMakelists.txt
echo "project(${1})" | cat >> CMakelists.txt
echo "" | cat >> CMakelists.txt
echo "set(CMAKE_CXX_STANDARD 17)" | cat >> CMakelists.txt
echo "" | cat >> CMakelists.txt
echo "add_executable(${1} ${2})" | cat >> CMakelists.txt
cp main.cpp ${2} 
