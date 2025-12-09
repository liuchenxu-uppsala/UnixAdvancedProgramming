//
// Created by Chenx on 2025/12/9.
//
#include <dirent.h>
#include <stdio.h>

int main(int argn,char* argv[]) {
    if (argn !=2) {
        printf("useage error");
        return 1;
    }
    DIR* dirctory;
    struct dirent * entry;
    dirctory = opendir(argv[1]);
    if (dirctory != NULL) {
        while ((entry = readdir(dirctory)) != NULL) {
            printf("name:%s,innode:%ld\n",entry->d_name,entry->d_ino);
        }
    }
    return 0;
}
