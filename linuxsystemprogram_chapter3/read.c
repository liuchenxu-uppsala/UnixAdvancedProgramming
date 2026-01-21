#include <stdio.h>

int main(void) {
    FILE* file = fopen("test.txt", "rb"); // 用二进制模式打开，不放过任何隐藏字符
    if (file == NULL) return 1;

    int c;
    printf("--- 开始解析文件字节流 ---\n");
    // while ((c = fgetc(file)) != EOF) {
    //     if (c == '\n') {
    //         printf("[换行符 (ASCII 10)]\n");
    //     } else if (c == '\r') {
    //         printf("[回车符 (ASCII 13)]\n");
    //     } else if (c == ' ') {
    //         printf("[空格 (ASCII 32)]\n");
    //     } else {
    //         printf("[字符: %c (ASCII %d)]\n", c, c);
    //     }
    // }
    // int char_line = fgetc(file);
    int char_line;
    while ((char_line = fgetc(file)) != EOF) {
        printf("%c", char_line);
    }
    printf("--- 解析结束 ---\n");

    fclose(file);
    return 0;
}