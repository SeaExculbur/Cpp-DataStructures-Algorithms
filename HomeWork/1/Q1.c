#include <stdio.h>
void reverse(int *left, int *right);

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int *p = a;
    int len = sizeof(a) / sizeof(int);
    for (int i = 0 ; i < len ; i++)
    {
        printf("%d\n" , *(p+i));
    }
    printf("---------------\n");
    reverse(&a[0] , &a[4]);
    for (int i = 0 ; i < len ; i++)
    {
        printf("%d\n" , *(p+i));
    }
    return 0;
}

void reverse(int *left, int *right)
{
    if (left == NULL || right == NULL)
    {
        return;
    }
    int temp;
    for (int i = 0; i < ((right - left) / 2) ; i++)
    {
        if ((left+i) != (right+i))
        {
            temp = *(left+i);
            *(left+i) = *(right-i);
            *(right-i) = temp;
        }
    }
}