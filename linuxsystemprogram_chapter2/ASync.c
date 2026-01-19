//
// Created by desheng on 1/19/26.
//
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void handler(int sig_no) {
    if (sig_no == SIGIO) {
        write(1,"Received SIGIO signal\n",22);
    }
}
struct sigaction act;
int main() {
    act.sa_flags = 0;
    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    memset(&act.sa_mask,0,sizeof(act.sa_mask));
    sigaction(SIGIO,&act,NULL);

    int flag = fcntl(STDIN_FILENO,F_GETFL,0);
    fcntl(STDIN_FILENO,F_SETOWN,getpid());
    fcntl(STDIN_FILENO,F_SETFL,flag|O_ASYNC);

    long count = 0;
    while (1) {
        printf("count: %ld\n",count++);
        fflush(stderr);
        sleep(1);
    }
}