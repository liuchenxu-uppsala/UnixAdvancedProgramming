//
// Created by Chenx on 2026/1/24.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set fd_sets;
    FD_ZERO(&fd_sets);
    FD_SET(STDIN_FILENO, &fd_sets);
    int result = select(STDIN_FILENO + 1, &fd_sets, NULL, NULL, NULL);
    if (result == -1) {
        perror("select");
    } else if (result == 0) {

    } else {
        if (FD_ISSET(STDIN_FILENO, &fd_sets)) {
            char input[100];
            read(STDIN_FILENO, input, 100);
            printf("%s\n",input);
        }
    }
}
