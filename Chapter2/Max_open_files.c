//
// Created by Chenx on 2025/12/9.
//

#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#ifdef OPEN_MAX
static long number_open_files =  OPEN_MAX;
#else
static long number_open_files = 100;
#endif

size_t get_max_open_files_num() {
    size_t opened_files_num;
    errno = 0;
    if ((opened_files_num = sysconf(_SC_OPEN_MAX)) < 0) {
        if (errno == 0 ) {
            opened_files_num = 100;
        }
    }
    printf("number_open_files:%ld\n",number_open_files);
    return opened_files_num;
}

int main() {
    size_t t = get_max_open_files_num();
    printf("get_max_open_files_num:%ld\n",t);
}


