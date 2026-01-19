#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

struct sigaction act;
void sig_handler(int signo) {
    if (signo == SIGIO) {
        write(2,"ReceivedSignal\n",14);
    }
}
int main(void) {
    printf("Hello, World!\n");
    memset(&act, 0, sizeof(act));
    act.sa_handler = sig_handler;
    act.sa_flags = 0;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGIO, &act, NULL);
    fcntl(STDIN_FILENO,F_SETOWN,getpid());
    int flags = fcntl(STDIN_FILENO,F_GETFL);
    fcntl(STDIN_FILENO,F_SETFL,O_ASYNC | flags);
    long count = 0;
    while(1) {
        printf("count:%ld\n",count++);
        fflush(stdout);
        sleep(1);
    }
    return 0;
}