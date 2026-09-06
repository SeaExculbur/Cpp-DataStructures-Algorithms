#include <stdio.h>
int count_equal(const int *p, int n, int target ,int *count);

int main()
{
    int arr[] = {1 ,2 ,3 ,3 ,4 ,4 ,5 ,6 ,7 ,8};
    const int *p = arr;
    int target = 3;
    int len = sizeof(arr) / sizeof(int);
    int count = 0;
    int ret = count_equal(p ,len ,target ,&count);
    if (ret != 0)
    {
        printf("程序运行失败\n");
        return 1;
    }
    printf("%d\n" , count);
    return 0;
}

int count_equal(const int *p, int n, int target ,int *count)
{
    if (p == NULL || n <= 0 || count == NULL)
    {
        return -1;
    }
    int c = 0;
    for (int i = 0 ; i < n ; i++)
    {
        if (*(p+i) == target)
        c++;
    }
    *count = c;
    return 0;
}