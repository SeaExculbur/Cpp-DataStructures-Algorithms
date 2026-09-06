#include <stdio.h>
int sum2d_fixed_col3(const int (*p)[3], int rows , int *sum);

int main()
{
    // 二维数组声明时只能省略第一维，后续维度必须明确（如 int a[][3]），否则编译器无法确定元素偏移与内存布局。
    int arr[3][3] = 
    {
        {1 ,2 ,3},
        {4 ,5 ,6},
        {7 ,8 ,9}
    };
    const int (*p)[3] = arr;
    int sum = 0;
    int ret = sum2d_fixed_col3(p ,3 ,&sum);
    if (ret != 0)
    {
        printf("程序运行失败\n");
        return 1;
    }
    printf("%d\n" , sum);
    return 0;
}

int sum2d_fixed_col3(const int (*p)[3], int rows , int *sum)
{
    if (p == NULL || rows <= 0 || sum == NULL)
    {
        return -1;
    }
    int temp = 0;
    for (int i = 0 ; i < rows ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        temp += *(*(p+i)+j);
    }
    *sum = temp;
    return 0;
}