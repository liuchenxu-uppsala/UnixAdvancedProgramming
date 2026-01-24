//
// Created by Chenx on 2026/1/24.
//

#include <sys/epoll.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int epfd = epoll_create1(0);
    struct epoll_event event;
    struct epoll_event events[5];
    event.events = EPOLLIN;
    event.data.fd = STDIN_FILENO;
    epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);
    while (1) {
        int nfds =epoll_wait(epfd,events,5,-1);
        for (int i = 0; i < nfds; i++) {
            char buffer[50] = {0};
            read(events[i].data.fd,buffer,20);
            printf("%s\n",buffer);
        }
    }
}
