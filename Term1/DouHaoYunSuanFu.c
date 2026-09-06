#include <stdio.h>

int main()
{
    int a;
    int b;
    printf("请输入一个数据：\n");
    scanf("%d" , &a);
    printf("该数据的绝对值为：%d\n" , (b = a < 0 ? -a : a));

    //第二次运算：
    //除以三取余
    int c = b % 3;
    printf("%d除以3并取余为:%d\n" , b , c );
    //乘10;
    int d = c * 10;
    printf("%d乘以10得到：%d\n" , c , d);

    //运用逗号运算符进行计算：
    int a1;
    scanf("输入一个数：");
    int num;
    // 从左到右，每次运算结束后，运算结果会自动赋值给原变量。
    num = a1 > 0 ? a1 : -a1 , a1 % 3 , a1 * 10;
    return 0;
}