#include <stdio.h>
#include <dirent.h>
#include "../lib/apue.h"

int main(int argc,char* argv[]) {
    if (argc !=2 ) {
        return 0;
    }
    DIR* dir;
    struct dirent* direntry;
    dir = opendir(argv[1]);
    if (dir != NULL ) {
        while ((direntry = readdir(dir))!= NULL) {
            printf("%s\n",direntry->d_name);
        }
    }
}