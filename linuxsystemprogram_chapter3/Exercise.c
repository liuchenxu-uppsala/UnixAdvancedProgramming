//
// Created by Chenx on 2026/1/21.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    struct s_stu {
        int age;
        char* name;
        char* gender;
    } student,specific_student={20,"LiLi","girl"};
    FILE* student_file = fopen("data","w");
    if (student_file == NULL) {
        perror("fopen");
        return 1;
    }
    int ret = fwrite(&specific_student,sizeof(struct s_stu),1,student_file);
    if (ret < 1) {
        perror("fwrite");
        return 1;
    }
    ret = fclose(student_file);
    if (ret == EOF) {
        perror("fclose");
        return 1;
    }
    student_file = fopen("data","r");
    if (student_file == NULL) {
        perror("fopen");
        return 1;
    }
    ret = fread(&student,sizeof(struct s_stu),1,student_file);
    if (ret < 1) {
        perror("fread");
        return 1;
    }
    ret = fclose(student_file);
    if (ret == EOF) {
        perror("fclose");
        return 1;
    }
    printf("student,name:%s,age:%d,gender:%s\n",student.name,student.age,student.gender);
}