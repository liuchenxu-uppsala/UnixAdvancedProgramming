//
// Created by Chenx on 2026/1/24.
//
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/fcntl.h>

void set_o_nonblock(int fd) {
    int flags = fcntl(fd, F_GETFL);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}
int main() {
    int read_write[2];
    pipe(read_write);
    int fd_read = read_write[0];
    int fd_write = read_write[1];
    char* long_content = "This is a very long string that we will read in tiny chunks to test epoll ET mode logic...";
    set_o_nonblock(fd_read);
    write(fd_write, long_content, strlen(long_content));
    int epfd = epoll_create1(0);
    struct epoll_event watch;
    struct epoll_event events[10];
    watch.events = EPOLLIN | EPOLLET;
    watch.data.fd = fd_read;
    epoll_ctl(epfd, EPOLL_CTL_ADD, fd_read, &watch);
    while (1) {
        int nums = epoll_wait(epfd, events, 10, -1);
        for (int i = 0; i < nums; i++) {
            if (watch.data.fd == fd_read) {
                char tiny_buf[10];
                while (1) {
                    int n = read(fd_read, tiny_buf, 9);
                    tiny_buf[n] = '\0';
                    if (n==0) {
                        break;
                    } else if (n==-1) {
                        if (errno == EAGAIN || errno == EWOULDBLOCK) {
                            break;
                        }
                    } else {
                        printf("%s",tiny_buf);
                    }
                }
                close(fd_read);
            }
        }
        close(fd_read);
        close(fd_write);
        close(epfd);
    }
}