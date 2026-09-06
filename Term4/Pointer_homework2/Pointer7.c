#include <stdio.h>
int sum(const int (*p)[4] ,int rows ,int *out);

int main()
{
    int a[3][4] = 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    const int (*p)[4] = a;
    int out = 0;
    int ret = sum(p ,3 ,&out);
    if (ret != 0)
    {
        printf("程序运行错误\n");
        return 1;
    }
    printf("%d\n" , out);
    return 0;
}

int sum(const int (*p)[4] ,int rows ,int *out)
{
    if (p == NULL || rows <= 0 || out == NULL)
    {
        return 1;
    }
    int temp = 0;
    for (int i = 0 ; i < rows ; i++)
    {
        // 定义temp_rows 用于存储每一行的和
        int temp_rows = 0;

        for (int j = 0 ; j < 4 ; j++)
        {
            temp += *(*(p + i)+j);
            temp_rows += *(*(p + i)+j);
        }
    }
    *out = temp;
    return 0;
}