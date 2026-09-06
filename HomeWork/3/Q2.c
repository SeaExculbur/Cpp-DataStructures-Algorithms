#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int id;
    char name[100];
    int age;
} stu;

int main()
{
    stu s1 = {1 ,"小刚" ,10};
    stu s2 = {2 ,"小王" ,12};
    stu s3 = {3 ,"小红" ,11};
    stu s4 = {4 ,"小蓝" ,19};
    stu s5 = {5 ,"小明" ,14};
    stu *p = malloc(sizeof(stu) * 5);
    p[0] = s1;
    for (int i = 0 ; i < 5 ; i++)
    {
        printf("%d %s %d" , )
    }
    return 0;
}