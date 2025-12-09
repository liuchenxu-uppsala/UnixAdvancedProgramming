//
// Created by Chenx on 2025/12/5.
//
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#define MAX_SIZE 1024

void signal_handler(int num) {
    if (num == SIGINT) {
        printf("signal_handler\n");
    }
}

int main() {
    char buff[MAX_SIZE];
    int pid;
    printf("%%:");
    if (signal(SIGINT,signal_handler) == SIG_ERR) {
        printf("Singnal Error");
    }
    while (fgets(buff,MAX_SIZE,stdin) != NULL) {
        if (buff[strlen(buff) - 1] == '\n') {
            buff[strlen(buff) - 1] = 0;
        }
        if ((pid = fork()) < 0) {
            printf("fork error\n");
        } else if (pid == 0 ) {
            execlp(buff,buff,(char*)0);
        } else {
            int* status = 0;
            waitpid(pid,status,0);
        }
        printf("%%:");
    }
}