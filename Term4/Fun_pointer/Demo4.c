#include <stdio.h>
int (*select_op(char c))(int ,int);
int add(int num1 ,int num2);
int sub(int num1 ,int num2);
int mul(int num1 ,int num2);

int main()
{
    char choose;
    printf("请输入+ 或 - 或 * 以返回函数指针\n");
    scanf("%c" , &choose);
    if (choose != '+' && choose != '-' && choose != '*')
    {
        printf("输入的字符非法\n");
        return 1;
    }
    int num1 ,num2;
    printf("请输入num1和num2\n");
    scanf("%d %d" , &num1 ,&num2);
    int (*op)(int ,int) = select_op(choose);
    if (op == NULL)
    {
        printf("函数指针为空\n");
        return 1;
    }
    int res = op(num1 ,num2);
    printf("%d" , res);
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

int mul(int num1 ,int num2)
{
    return num1 * num2;
}

int (*select_op(char c))(int, int)
{
    if (c == '*')
    {
        return mul;
    }
    else if (c == '+')
    {
        return add;
    }
    else if (c == '-')
    {
        return sub;
    }
    else
    {
        return NULL;
    }
}