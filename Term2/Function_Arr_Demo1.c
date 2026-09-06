#include <stdio.h>
void func1(int arr[] , int len);
int main()
{
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr) / sizeof(int);
    printf("%d\n" , len);
    // 调用函数
    func1(arr , len);
    return 0;
}
void func1(int arr[] , int len)
    // 把数组作为传入参数传入函数里，数组会退化成指针，指向第一个内存地址。
{
        printf("%d\n", *arr);
}