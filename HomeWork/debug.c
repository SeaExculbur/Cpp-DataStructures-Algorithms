#include <stdio.h>

int main()
{
    int m[2][3] = {{1,2,3},{4,5,6}};
    int (*p)[3] = m;
    printf("%d , %d , %d\n" , (*p)[0] , (*p)[2] , (*(p+1))[1]);
    for (int i = 0 ; i < 2 ; i++)
    {
        for (int j = 1 ; j < 3 ; j++)
        {
            printf("%d\n" , *(*(p+i)+j));
        }
    }
    return 0;
}