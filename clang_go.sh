#!/bin/sh

# Trim ".c" from the end of the filename
FILE=${1%.c}

# Delete the existing binary and fail silently if it's not there
rm build/$FILE 2> /dev/null

# Compile the file using the latest C options
clang -Wall -Wextra -std=c2x -o build/$FILE $FILE.c

# Run the binary
./build/$FILE
