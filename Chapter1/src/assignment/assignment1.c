//
// Created by Chenx on 2025/12/5.
//
#include <dirent.h>
#include <stdio.h>
int main(int argc,char* argv[]) {
    if (argc != 2) {
        printf("usage error!");
    }
    DIR* dictory;
    struct dirent* entry;
    dictory = opendir(argv[1]);
    while ((entry = readdir(dictory)) != NULL) {
        printf("%s:%ld\n",entry->d_name,entry->d_ino);
    }
}