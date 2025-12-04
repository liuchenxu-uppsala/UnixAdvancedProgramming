cmake_minimum_required(VERSION 3.22)
project(LS C)

set(CMAKE_C_STANDARD 99)
include_directories(lib)
add_executable(LS src/main.c
        lib/error.c)
