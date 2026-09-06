#include <stdio.h>
int add(int num1 ,int num2);
int sub(int num1 ,int num2);
int mut(int num1 ,int num2);

int main()
{
    int index ,num1 ,num2;
    printf("请分别输入三个数据，依次为：index ，num1，num2   [index为1，2，3时，分别对应add, sub, mut]\n");
    scanf("%d %d %d" , &index ,&num1 ,&num2);
    if (index > 3 || index < 1)
    {
        printf("index不合法\n");
        return 1;
    }
    int (*ops[3])(int ,int) = {add , sub , mut};
    int res = ops[index - 1](num1 ,num2);
    printf("%d\n" , res);
    return 0;
}

int add(int num1 ,int num2)
{
    return num1 + num2;
}

int sub(int num1 ,int num2)
{
    return num1 - num2;
}

int mut(int num1 ,int num2)
{
    return num1 * num2;
}