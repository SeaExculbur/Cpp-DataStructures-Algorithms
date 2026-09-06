#include <stdio.h>
#include <string.h>
struct Student
{
    char name[10];
    char gender;
    int age;
};

int main()
{
    struct Student stu1 = {"小明" , 'M' , 10};
    strcpy(stu1.name , "小王");
    printf(stu1.name);
    return 0;
}