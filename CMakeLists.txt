cmake_minimum_required(VERSION 3.30)

project(c_learning C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(booleans src/booleans.c)
add_executable(custom_bit_ints src/custom_bit_ints.c)
add_executable(double src/double.c)
add_executable(function_pointer src/function_pointer.c)
add_executable(heap src/heap.c)
add_executable(packed_struct_union src/packed_struct_union.c)
add_executable(pointers src/pointers.c)
