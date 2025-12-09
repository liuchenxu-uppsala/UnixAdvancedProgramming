#include <stdio.h>
//
// Created by Chenx on 2025/12/9.
//
int main() {
    int char_getc;
    while ((char_getc = getc(stdin)) != EOF) {
        putchar(char_getc);
    }
}