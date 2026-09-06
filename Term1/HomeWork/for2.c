#include <stdio.h>
int main()
{
    int m,n;
    m = 0;
    for (int i = 1 ; i <= 5 ; i++)
    {
        n = m + i;
        m = n;

    }
    printf("%d\n" , n);
    // 更简洁的写法：

    int sum = 0;
    for (int k = 1 ; k <= 5 ; k++)
    {
        sum = sum + k;
    }
    printf("%d\n" , sum);

    return 0;
}