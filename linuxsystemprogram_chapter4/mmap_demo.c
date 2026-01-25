//
// Created by Chenx on 2026/1/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/signal.h>
#include <sys/mman.h>

void handler_signal(int sig) {
    if (sig == SIGSEGV) {
        printf("error: SIGSEGV\n");
    } else if (sig == SIGBUS) {
        printf("error: SIGBUS");
    }
    exit(EXIT_FAILURE);
}

int main() {
    int fd = open("test_mmap.bin",O_RDWR | O_CREAT | O_TRUNC, 0666);
    long int page_size = sysconf(_SC_PAGESIZE);
    truncate("test_mmap.bin",page_size);

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handler_signal;
    sigaction(SIGBUS,&sa,NULL);
    sigaction(SIGSEGV,&sa,NULL);

    char* ptr = mmap(NULL,page_size,PROT_READ,MAP_SHARED,fd,0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
    }
    //ptr[0] = 'H';

    truncate("test_mmap.bin",0);
    char c = ptr[0];
}