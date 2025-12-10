//
// Created by Chenx on 2025/12/9.
//
#include <stdio.h>
#include <unistd.h>
int main() {
    long max_children = sysconf(_SC_CHILD_MAX);
    long name_max = pathconf("/",_PC_PATH_MAX);
    printf("max_children:%ld,name_max:%ld\n",max_children,name_max);
}