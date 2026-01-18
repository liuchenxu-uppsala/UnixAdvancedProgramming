//
// Created by desheng on 1/18/26.
//

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char *fifo_path = "/tmp/test_fifo";
    char buff[100];
    int fd = open(fifo_path, O_RDONLY);
    read(fd,buff,100);
    printf("%s\n",buff);
}