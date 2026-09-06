#include <stdio.h>
int add(int a, int b);
int sub(int a, int b);

int main()
{
    int (*op)(int, int);
    op = add;
    int res1 = (*op)(7 ,3);
    printf("%d\n" , res1);
    int res1 = op(7 ,3);
    op = sub;
    int res2 = op(7 ,3);
    printf("%d %d\n" , res1 , res2);
    res2 = (*op)(7 ,3);
    printf("%d\n" , res2);
    return 0;
}

int add(int a, int b)
{
    return a+b;   
}

int sub(int a, int b)
{
    return a-b;
}