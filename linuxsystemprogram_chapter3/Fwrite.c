//
// Created by Chenx on 2026/1/21.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("test.txt", "a");
    if (file == NULL) return 1;
    fputs("Let me try to write to text.txt",file);
    fflush(file);
    fclose(file);
}