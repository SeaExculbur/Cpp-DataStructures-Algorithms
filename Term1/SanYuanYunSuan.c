#include <stdio.h>

int main()
{
    //三元运算符的应用
    //格式：
    // 关系表达式 ？ 表达式1：表达式2；
    // int a = 10;
    // int b = 20;
    // int c = a > b ? a : b;
    // 如果关系表达式成立，那么输出表达式1，否则输出表达式2
    // printf("%d\n" , c);
    // printf("%d\n" , a > b ? a : b);

    //获取三个变量的最大值
    printf("-------------------------------\n");
    int a = 10 , b = 20 , c = 30;
     int num = a > b ? a : b;
     printf("%d" , num > c ? num : c);

    return 0;
}