cmake_minimum_required(VERSION 3.22.1)
project(linuxsystemprogram_chapter2 C)

set(CMAKE_C_STANDARD 11)

add_executable(linuxsystemprogram_chapter2
        #main.c
        #ASync.c
        #Poll.c
        select.c)
