//
// Created by Chenx on 2025/12/11.
//
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef PATH_MAX
static int path_longest = PATH_MAX;
#else
static int path_longest = 0;
#endif

#define SUGGEST_LENGTH 200

char* get_longest_path(int* length) {
    int local_length = 0;
    errno = 0;
    if (path_longest <= 0) {
        if ((local_length = pathconf("/",_PC_PATH_MAX)) > 0) {

        } else {
            if (errno == 0) {
                local_length = SUGGEST_LENGTH;
            } else {
                perror("get_longest_path");
            }
        }
    } else {
        local_length = path_longest;
    }
    char* pr = (char*)malloc(local_length);
    *length = local_length;
}

int main() {
    int local_length;
    get_longest_path(&local_length);
    printf("PATH_MAX:%d\n",local_length);
    return 0;
}
