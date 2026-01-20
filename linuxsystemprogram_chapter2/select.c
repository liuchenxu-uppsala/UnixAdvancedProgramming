//
// Created by Chenx on 2026/1/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    printf("提示：程序正在 select 你的键盘，请输入...\n");
    while (1) {
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);
        int ret = select(STDIN_FILENO+1, &readfds, NULL, NULL, NULL);
        if (ret == -1) {
            perror("select");
        } else {
            if (ret == 0) {
                printf("select timeout\n");
            } else {
                char buf[1024];
                ssize_t len = read(STDIN_FILENO,buf,1024);
                buf[len] = '\0';
                printf("Poll ready to read: %s\n",buf);
            }
        }
    }
}