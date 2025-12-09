//
// Created by Chenx on 2025/12/5.
//
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("current PID:%d\n",getpid());
    int char_value;
    while ((char_value = getc(stdin)) != EOF) {
        putc(char_value,stdout);
    }
}
