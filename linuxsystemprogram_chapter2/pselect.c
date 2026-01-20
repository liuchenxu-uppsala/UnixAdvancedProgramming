//
// Created by Chenx on 2026/1/20.
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    fd_set readfds;
    printf("准备输入吧在监听\n");
    while (1) {
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);
        int ret = pselect(STDIN_FILENO+1, &readfds, NULL, NULL, NULL, NULL);
        if (ret == -1) {
            perror("pselect");
        } else {
            if (ret == 0) {
                printf("timeout\n");
            } else {
                char buffer[1024] = {0};
                read(STDIN_FILENO, buffer, 1024);
                printf("Poll ready to read: %s\n",buffer);
            }
        }
    }
}