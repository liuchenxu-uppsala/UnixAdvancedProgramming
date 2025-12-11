//
// Created by Chenx on 2025/12/11.
//
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#ifdef _POSIX_THREADS
#if _POSIX_THREADS > 0
static bool support_thread = true;
#else
static bool support_thread = false;
#endif
#else
static bool support_thread = false;
#endif

bool is_support_thread() {
    long result;
    if (support_thread)
        return true;
    else {
        errno = 0;
        if ((result = sysconf(_SC_THREADS)) > 0) {
            return true;
        } else {
            if (result == -1 && errno == 0) {
                return false;
            } else {
                printf("调用sysconf 报错!");
                return false;
            }
        }
    }
}

int main() {
    printf("%d\n",is_support_thread());
}