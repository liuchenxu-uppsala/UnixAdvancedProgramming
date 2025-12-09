//
// Created by Chenx on 2025/12/5.
//
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main() {
    fprintf(stderr,"error:%s\n",strerror(EBADSLT));
    errno = EBADMSG;
    perror("Error:");
}
