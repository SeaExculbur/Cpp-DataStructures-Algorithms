#include <stdio.h>

int main()
{
    // int a;
    // int b = 10;
    // printf("请输入一个数据：");
    // scanf("%d" , &a);
    // printf("%d\n" , a);
    // int num = a == b;
    // printf("%d\n" , num);
    // ++num;
    // printf("经过一次++后，其结果为：%d" , num);
    int a = 10;
    int b = 15;
    int num;
    num = a + b++ + b - --a;
    printf("%d %d %d " , num , a ,b);

    return 0;
}