cmake_minimum_required(VERSION 3.22)
project(LS C)

set(CMAKE_C_STANDARD 99)
include_directories(lib)
add_executable(LS
        # src/main.c
        lib/error.c
        #src/STDIO.c
        #src/STDChar.c
        #src/Process.c
        #src/Time.c
        #src/assignment/assignment1.c
        #src/assignment/ReadWrite.c
        #src/assignment/ProcessCMD.c
        #src/assignment/ProcessCMD2.c
        #src/assignment/ReadWrite2.c
        #src/assignment/GetPutChar.c
        #src/assignment/Error.c
        src/assignment/Time.c
        #src/Error.c
)
