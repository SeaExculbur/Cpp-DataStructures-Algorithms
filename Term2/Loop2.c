#include <stdio.h>
int main()
{
    long long result = 0;
    for (int i = 1 ; i <= 10 ; i++)
        {
            long long pow = 1;
        for (int j = 1 ; j <= i ; j++)
            {
                pow = pow * i;
            }
        result = pow + result;
        }
    printf("%lld" , result);
    return 0;
}