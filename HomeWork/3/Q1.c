#include <stdio.h>
void bubble_sort(int class[] , int len);

int main()
{
    int class[] = {32 , 54 ,11 ,76 ,90 ,43 ,89};
    int len = sizeof(class) / sizeof(int);
    bubble_sort(class ,len);
    for (int i = 0 ; i < len ; i ++)
    {
        printf("%d\n" , class[i]);
    }
    return 0;
}

void bubble_sort(int class[] , int len)
{
    int temp;
    for (int i = 0 ; i < len-1 ; i++)
    {
        for (int j = 0 ; j < len- 1 - i ; j++)
        {
            if (class[j] > class[j+1])
            {
                temp = class[j];
                class[j] = class[j+1];
                class[j+1] = temp;
            }
        }
    }
}