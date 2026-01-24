//
// Created by Chenx on 2026/1/24.
//
#include <stdio.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd = open("file.txt", O_RDONLY);
    struct iovec iov[3] = {};
    char* buf[3];
    buf[0] =  (char*) malloc(sizeof(char) * 50);
    buf[1] =  (char*) malloc(sizeof(char) * 50);
    buf[2] =  (char*) malloc(sizeof(char) * 50);

    iov[0].iov_base = buf[0];
    iov[0].iov_len = 50;

    iov[1].iov_base = buf[1];
    iov[1].iov_len = 50;

    iov[2].iov_base = buf[2];
    iov[2].iov_len = 50;

    readv(fd, iov, 3);


    printf("%s\n", buf[0]);
    printf("%s\n", buf[1]);
    printf("%s\n", buf[2]);
}