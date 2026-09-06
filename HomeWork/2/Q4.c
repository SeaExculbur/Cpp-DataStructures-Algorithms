#include <stdio.h>
#include <stdlib.h>
typedef struct 
{ 
    double score; 
    int id; 
} Student;

Student *make_class(int n);

int main()
{
    int n;
    printf("请输入你要分配几个学生结构体\n");
    if (scanf("%d" , &n) != 1)
    {
        printf("输入无效\n");
        return 1;
    }
    Student *p = make_class(n);
    if (p == NULL)
    {
        printf("分配失败\n");
        return 1;
    }
    for (int i = 0 ; i < n ; i++)
    {
        int id;
        double score;
        printf("请输入第%d个学生的id和分数\n" , i+1);
        if (scanf("%d" , &id) != 1)
        {
            printf("输入无效\n");
            return 1;
        }
        if (scanf("%lf" , &score) != 1)
        {
            printf("输入无效\n");
            return 1;
        }
        p[i].id = id;
        p[i].score = score;
        printf("%d\n" , p[i].id);
        printf("%lf\n" ,p[i].score);
    }
    free(p);
    return 0;
}

Student *make_class(int n)
{
    if (n <= 0)
    {
        return NULL;
    }
    Student *p = malloc(sizeof(Student) * n);
    return p;
}