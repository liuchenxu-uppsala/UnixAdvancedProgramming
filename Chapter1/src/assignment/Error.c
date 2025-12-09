//
// Created by Chenx on 2025/12/9.
//
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main() {
    printf("error1:%s",strerror(ENOANO));
    errno  = EBADFD;
    perror("Error_cx2");
}
