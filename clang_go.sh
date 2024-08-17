#!/bin/sh
rm build/$1 2> /dev/null
clang -std=c2x -o build/$1 $1.c
./build/$1
