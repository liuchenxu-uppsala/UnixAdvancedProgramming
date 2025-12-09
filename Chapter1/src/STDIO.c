#include <unistd.h>
#include <stdio.h>
#define BUFF_SIZE 4096
int main() {
    int num;
    char buff[BUFF_SIZE];
    while ((num = read(STDIN_FILENO,buff,BUFF_SIZE)) > 0) {
        write(STDOUT_FILENO,buff,num);
    }
}