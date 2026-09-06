#include <stdio.h>
int main()
{
    for (int i = 1 ; i <= 9 ; i++)
        for (int j = 1 ; j <= i ; j++)
        {
            printf("%d X %d = %d\t" , j , i , j * i);
            if (j == i)
            printf("\n");
        }
    return 0;
}