#include <stdio.h>
int Find_Max(int arr[] , int len);
int main()
{
    // 定义一个数组
    int arr[] = {4 ,5 ,6 ,3 ,9 ,10 ,15};
    // 获取数组长度
    int len = sizeof(arr) / sizeof(int);
    int max_num = Find_Max(arr , len);
    printf("%d\n" , max_num);
    return 0;
}

int Find_Max(int arr[] , int len)
{
        int temp = arr[0];
    for (int i = 0 ; i < len-1 ; i++)
    {
  
        if (arr[i] < arr[i + 1]) 
        {
            // 定义一个临时变量，存储大的数据
            temp = arr[i + 1];
        }
    }
    return temp;
}