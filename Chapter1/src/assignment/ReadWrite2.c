#include <unistd.h>
//
// Created by Chenx on 2025/12/9.
//
#define SIZE 100
int main() {
    char buff[SIZE];
    int num;
    while ((num = read(STDIN_FILENO,buff,SIZE) )!= -1) {
        write(STDOUT_FILENO,buff,num);
    }
}