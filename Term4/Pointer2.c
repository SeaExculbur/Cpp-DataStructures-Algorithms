#include <stdio.h>
int main()
{
    int arr1[] = {11 ,22 ,33 ,44 ,55 ,66};
    int arr2[] = {111 ,222 ,333 ,444 ,555 ,666};
    int (*arr[2])[6] = {&arr1 ,&arr2};
    int (**p)[6] = arr;
    for (int i = 0 ; i < 2 ; i++)
    {
        for (int j = 0 ; j < 6 ; j++)
        {
            printf("%d\n" , *(**p + j));
        }
        printf("\n");
        p++;
    }

    return 0;
}