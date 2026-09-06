#include <stdio.h>
int main()
{
    // 求 100 以内所有偶数之和
    int sum = 0;
    for (int i = 1 ; i <= 50 ; i++)
    {
        sum = i * 2 + sum;
    }
    printf("%d" , sum);
    return 0;
}