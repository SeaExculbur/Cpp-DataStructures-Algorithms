#include <stdio.h>
int min_max(const int *p, int n, int *minv, int *maxv);
int main()
{
    int arr[3] = {1 ,2 ,3};
    const int *p = arr;
    int minv = arr[0];
    int maxv = arr[0];
    int ret = min_max(p , 3, &minv, &maxv);
    if (ret != 0)
    {
        printf("程序运行失败\n");
        return 1;
    }
    printf("最大值：%d\n" , maxv);
    printf("最小值：%d\n" , minv);
    return 0;
}

int min_max(const int *p, int n, int *minv, int *maxv)
{
    if (p == NULL || n <= 0 || minv == NULL || maxv == NULL)
    {
        return -1;
    }
    for (int i = 1 ; i < n ; i++)
    {
        if (*(p+i) < *minv)
        {
            *minv = *(p+i);
        }
        if (*(p+i) > *maxv)
        {
            *maxv = *(p+i);
        }
    }
    return 0;
}