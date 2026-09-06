#include <stdio.h>
int main()
{
    // 变量的生命周期：变量只在一个大括号之内生效。
    if (1)
    {
        int a = 10;
        printf("%d\n" , a);
    }
    // printf("%d\n" , a); 是错的，因为变量不在这个括号内。
    int a = 20;
    printf("%d\n" , a);
}