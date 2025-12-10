#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/limits.h>
//
// Created by Chenx on 2025/12/9.
//
#ifdef PATH_MAX
static long max_path = PATH_MAX;
#else
static long max_path = 0;
#endif
#define DEFAULT_PATH_LENGTH_GUESS 1024
char* allocate_path_name(size_t* size) {
    errno = 0;
    if ((max_path = pathconf("/",_PC_PATH_MAX)) < 0) {
        if (errno == 0) {
            max_path = DEFAULT_PATH_LENGTH_GUESS;
        } else {
            perror("allocate_path_name: ");
            max_path = DEFAULT_PATH_LENGTH_GUESS;
        }
    }
    long sopen_version = sysconf(_SC_XOPEN_VERSION);
    long posix_version = sysconf(_SC_VERSION);
    if (sopen_version < 4 && posix_version < 200112L) {
        max_path = max_path + 1;
    }
    char * ptr =  (char*)malloc(max_path);
    *size = max_path;
    return ptr;
}

int main() {
    size_t length;
    char* return_value = allocate_path_name(&length);
    printf("max_path:%ld\n",length);
    return 0;
}