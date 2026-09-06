#include <stdio.h>
int main()
{
    int count = 0;
        int a,b;
    printf("请输入第一个数据：\n");
    scanf("%d" , &a);
    printf("请输入第二个数据：\n");
    scanf("%d" , &b);
    for (int i = a ; i <= b ; i++)
    {
        if (i % 6 == 0 && i % 8 == 0)
        {
            count++;
        }
    }
    printf("一共有%d个数可以被6和8整除" , count);
    return 0;
}