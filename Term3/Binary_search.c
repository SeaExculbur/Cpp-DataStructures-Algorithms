#include <stdio.h>
// 二分查找
int binary_search(int arr[] , int len , int num);
int main()
{
    // 定义任意一个数组
    int arr[] = {10, 21 ,33 ,54 ,88 ,90 ,97};
    // 获取数组长度
    int len = sizeof(arr) / sizeof(int);
    // 定义需要查找的数
    int num = 100;
    int index = binary_search(arr , len , num);
    printf("%d\n" , index);
    return 0;
}
int binary_search(int arr[] , int len , int num)
{
    // 定义最小和最大索引, 判断结束后用于二分索引.
    int min = 0;
    int max = len-1;
    // 定义查找的索引.
    int mid = (max - min) / 2;
    while (min <= max)
    {
    if (arr[mid] > num)
    {
        max = mid - 1;
        mid = (max + min) / 2;
    }
    else if (arr[mid] < num)
    {
        min = mid + 1;
        mid = (max + min) / 2;
    }
    else
    return mid;
    }
    return -1;
}