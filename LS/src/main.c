#include <stdio.h>
#include <dirent.h>
#include "../lib/apue.h"

int main(int argc,char* argv[]) {
    printf("Hello, World!\n");
    if (argc != 2) {
        err_quit("Usage: ./ls <pathname>");
    }
    DIR* dir;
    struct dirent* entry;
    dir = opendir(argv[1]);
    if (dir != NULL) {
        while ((entry  = readdir(dir)) != NULL) {
            printf("%s:\n",entry->d_name);
        }
    }
    return 0;
}