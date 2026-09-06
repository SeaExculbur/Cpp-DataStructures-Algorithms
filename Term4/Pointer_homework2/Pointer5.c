#include <stdio.h>
int sum_array(const int *p, int n ,int *sum);
void print_array(const int *p, int n);

int main()
{
    int arr[] = {1 ,2 ,3 ,4 ,5 ,6};
    const int *p = arr;
    int len = sizeof(arr) / sizeof(arr[0]);
    print_array(p ,len);

    int sum = 0;
    int ret = sum_array(p ,len ,&sum);
    if (ret != 0)
    {
        printf("程序运行失败\n");
        return 1;
    }
    printf("%d\n" ,sum);
    return 0;
}

void print_array(const int *p, int n)
{
    if (p == NULL || n <= 0 )
    {
        return;
    }

    for (int i = 0 ; i < n ; i ++)
    {
        printf("%d\n" , *(p+i));
    }
}

int sum_array(const int *p, int n ,int *sum)
{
    if (p == NULL || n <= 0 || sum == NULL)
    {
        return -1;
    }
    int temp = 0;
    for (int i = 0 ; i < n ; i++)
    {

        temp += *(p+i);
    }
    *sum = temp;
    return 0;
}