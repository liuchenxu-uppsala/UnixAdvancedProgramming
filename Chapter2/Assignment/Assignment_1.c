//
// Created by Chenx on 2025/12/9.
//
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#ifdef PATH_MAX
static long longest_path = PATH_MAX;
#else
static long longest_path = 0;
#endif

#define GUESS_VALUE 1024

char* safe_path_alloc() {
    long int length = 0;
    errno = 0;
    if ((length = pathconf("/",_PC_PATH_MAX))<0) {
        if (errno == 0) {
            length = GUESS_VALUE;
        } else {
            return NULL;
        }
    } else {
        length++;
    }
    return (char*)malloc(length++);
}