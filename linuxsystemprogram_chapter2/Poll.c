//
// Created by Chenx on 2026/1/20.
//
#include <poll.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct pollfd fds[1];
    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;
    printf("提示：程序正在 poll 你的键盘，请输入点东西按回车...\n");
    while (1) {
        int ret = poll(fds, 1, 1000);
        if (ret == -1) {
            perror("poll");
        } else {
            if (fds[0].revents & POLLIN) {
                char buf[1024];
                read(STDIN_FILENO,buf,1024);
                printf("Poll ready to read: %s\n",buf);
            }
        }
    }
}