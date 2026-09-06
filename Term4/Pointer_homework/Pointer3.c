#include <stdio.h>
int sum2d(int (*p)[3], int rows);

int main()
{
    // 定义数组及其指针
    int arr[2][3] = {{1,2,3},{4,5,6}};
    int (*p)[3] = arr;

    // 调用函数, 接收返回的和数
    int sum = sum2d(p , 2);
    printf("%d\n" , sum);
    return 0;
}

int sum2d(int (*p)[3], int rows)
{
    // temp用于存储加和数据
    int temp = 0;
    // 外部循环两遍, 让指针遍历一维整体数组
    for (int i = 0 ; i < rows ; i++)
    {
            // 内层循环三遍, 让指针遍历一维数组
            for (int j = 0 ; j < 3 ; j++)
        {
            // 打印数据, *(p + i) 表示指针指向哪个一维数组 外层再解引用+j 表示遍历到一维数组里的哪个数
            printf("%d\n" , *(*(p+i)+j));
            temp = temp + *(*(p+i)+j);
        }
    }
        return temp;
}