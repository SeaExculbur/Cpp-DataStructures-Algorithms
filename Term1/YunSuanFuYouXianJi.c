#include <stdio.h>

int main()
{
    // 三元运算符
    int num1 = 10 , num2 = 20 , num3 = 30, num4 = 40;
    int a = 10 > 20 ? ( 10 ): (30 < 20 ? 20 : 30);
    printf("%d\n" , a);
    int b = num1 < num2 ? (num3 > num4 ? num1 : num2 ): (num3);
    printf("%d" ,b);

    return 0;
}