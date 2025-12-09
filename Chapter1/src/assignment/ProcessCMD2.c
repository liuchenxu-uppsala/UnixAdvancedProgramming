#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
//
// Created by Chenx on 2025/12/9.
//
#define SIZE 1024
int main() {
    char buff[SIZE];
    int pid;
    int status;
    while (fgets(buff,SIZE,stdin) != NULL) {
        if (buff[strlen(buff)-1] == '\n') {
            buff[strlen(buff)-1] = 0;
        }
        if ((pid = fork()) < 0) {

        } else if (pid == 0) {
            execlp(buff,buff,(void*)0);
        } else {
            waitpid(pid,&status,0);
        }
    }
}