#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
//
// Created by Chenx on 2025/12/9.
//
#define SIZE 1024
int main(){
    char buffer[SIZE];
    int pid;
    int status;
    while (fgets(buffer,SIZE,stdin) != NULL) {
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = 0;
        }
        if ((pid = fork()) < 0) {
            printf("Usage");
        } else if (pid == 0) {
            execlp(buffer,buffer,(char*)0);
        } else {
            waitpid(pid,&status,0);
        }
    }
}