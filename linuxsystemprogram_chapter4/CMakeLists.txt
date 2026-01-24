cmake_minimum_required(VERSION 3.22)
project(linuxsystemprogram_chapter4 C)

set(CMAKE_C_STANDARD 11)

add_executable(linuxsystemprogram_chapter4
        #main.c
        #readv_demo.c
        #select_demo.c
        #poll_demo.c
        epoll_demo.c)
