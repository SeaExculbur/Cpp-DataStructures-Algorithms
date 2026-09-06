#include <stdio.h>
int main()
{
    // -if 的第一种格式：
    int a = 10;
    if (a > 20)
    {
        printf("该数据%d＞20" , a);
        // 如果表达式不符合条件，那么直接不输出结果。

    }

    // 细节1：在C语言里，如果判断的是一个数字，非0表示成立，0表示不成立。
    if (0)
    {
        printf("不成立");
    }
    
    // 细节2：如果大括号里语句只有一行，那么大括号可以省略不写。
    if (1)
    printf("直接执行即可\n");


    // if的第二种格式：
    // if - else 的使用
    int b;
    printf("请输入一个数据：\n");
    scanf("%d" , &b);
    if (b >= 100)
    {
        printf("该数据≥100\n");
    }
    else
    {
        printf("该数据＜100\n");
    }

    // if 的第三种格式：
    // if - else if - else (对应python的 if - elif - else)
    int c = 150;
    if (c >= 30 && c < 100)
    {
        printf("%d这个数据大于或等于30\n" , c);
    }
    else if (c >= 100)
    {
        printf("%d这个数据远大于30\n" , c);
    }
    else
    {
        printf("%d这个数据小于30\n" , c);
    }
    
    return 0;
}