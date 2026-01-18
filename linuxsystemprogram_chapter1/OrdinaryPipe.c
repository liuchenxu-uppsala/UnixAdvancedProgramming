//
// Created by desheng on 1/18/26.
//

#include <unistd.h>
#include <stdio.h>
int main() {
    int fds[2];
    char buffer[20];
    pipe(fds);
    int fork_result = fork();

    // 子进程
    if (fork_result == 0) {
        close(fds[1]);
        read(fds[0], buffer, 10);
        printf("Child read: %s\n", buffer);
        close(fds[0]);
    } else {
        close(fds[0]);
        write(fds[1], "Hi ordinary pipe", 10);
        close(fds[1]);
    }
    return 0;
}