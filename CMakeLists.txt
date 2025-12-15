cmake_minimum_required(VERSION 3.16)
project(test_c C)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_C_FLAGS "-ffreestanding -nostdlib -static -O2")
set(CMAKE_GENERATOR "Ninja")

add_executable(minecho main.c)