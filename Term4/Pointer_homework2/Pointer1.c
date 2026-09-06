#include <stdio.h>
int sum_array(const int *p, int n ,int *out_sum);

int main()
{
    int arr[] = {1 ,2 ,3 ,4 ,5 ,6};
    int len = sizeof(arr) / sizeof(int);
    const int *p = arr;
    int sum = 0;
    int ret = sum_array(p , len ,&sum);
    if (ret != 0)
    {
        printf("程序运行失败");
        return 1;
    }
    printf("%d\n" , sum);
    return 0;
}

int sum_array(const int *p, int n ,int *out_sum)
{
    if (p == NULL || n <= 0 || out_sum == NULL)
    {
        return -1;
    }
    int temp = 0;
    for (int i = 0 ; i < n ; i++)
    {
        temp += *(p+i);
    }
    *out_sum = temp;
    return 0;
}