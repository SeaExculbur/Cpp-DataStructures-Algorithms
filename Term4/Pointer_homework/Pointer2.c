#include <stdio.h>
int array_sum(const int *p, int n);
int main()
{
    int arr[] = {3, 5, 7, 9, 11};
    const int *p = arr;
    int len = sizeof(arr) / sizeof(int);
    int sum = array_sum(p , len);
    printf("%d\n" , sum);
    return 0;
}

int array_sum(const int *p, int n)
{
    int temp = 0;
    for (int i = 0 ; i < n ; i++)
    {
        printf("%d\n" , *(p+i));
        temp = temp + *(p+i);
    }
    return temp;
}
