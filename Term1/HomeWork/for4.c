#include <stdio.h>
int main()
{   
    // 输入两个数据，在两个数据之间求一共有多少个数据可以被6和8整除
    int a,b;
    printf("请输入第一个数据：\n");
    scanf("%d" , &a);
    printf("请输入第二个数据：\n");
    scanf("%d" , &b);
    if (a <= b)
    {
    int count = 0;
        for (int i = a ; i <= b ; i++)
        {
            int num1 = i % 6;
            if (num1 == 0)
            {
                int num2 = i % 8;
                if (num2 == 0)
                count++;
            }
        }
    printf("一共有%d个数据是可以在%d到%d内被6和8整除" , count , a , b);
    }
    else
    {
        int count = 0;
        for (int i = b ; i <= a ; i++)
        {
            int num1 = i % 6;
            if (num1 == 0)
            {
                int num2 = i % 8;
                if (num2 == 0)
                count++;
            }
        }
    printf("一共有%d个数据是可以在%d到%d内被6和8整除" , count , b , a);  
    }
    return 0;
}