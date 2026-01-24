//
// Created by Chenx on 2026/1/24.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <poll.h>
int main() {
    struct pollfd pfds[1];
    pfds[0].fd = STDIN_FILENO;
    pfds[0].events = POLLIN;
    int ret = poll(pfds, 1, -1);
    if (ret == -1) {
        perror("poll");
    } else if (ret == 0){
        perror("timeout");
    } else {
        if (pfds[0].revents & POLLIN) {
            char buffer[50] = {0};
            read(STDIN_FILENO,buffer,50);
            printf("%s",buffer);
        }
    }
}