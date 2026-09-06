#include <stdio.h>

int Interpolation_Search(int arr[] , int len , int num);

int main()
{
    // 插值查找法

    int arr[] = {2 ,10 ,22 ,58 ,64 ,89 ,94};
    int len = sizeof(arr) / sizeof(int);
    // 定义要查找的数num

    int num = 10;
    // 调用函数

    int index = Interpolation_Search(arr , len , num);
    printf("%d\n" , index);

    return 0;
}

int Interpolation_Search(int arr[] , int len , int num)

{
    // 定义最大、最小、插值索引
    int max ,min ,mid;
    min = 0;
    max = len -1;
    mid = min + ((num - arr[min]) / (arr[max] - arr[min])) * (max - min);

    // 如果mid大于max ，循环终止，说明此数不存在于数组内，返回-1
    while (min <= max)
    {
        if (arr[mid] > num)
        // 如果中值大于num，说明中值过大，让max等于mid-1，再找新的中值继续循环
        {
            max = mid - 1;
            mid = min + ((num - arr[min]) / (arr[max] - arr[min])) * (max - min);
        }

        else if (arr[mid] < num)
        // 如果中值小于num，说明中值过小，让min等于mid+1，再找新的中值继续循环
        {
            min = mid + 1;
            mid = min + ((num - arr[min]) / (arr[max] - arr[min])) * (max - min);
        }
        else
        return mid;
    }

    // 数据不存在的情况下返回-1
    return -1;
}