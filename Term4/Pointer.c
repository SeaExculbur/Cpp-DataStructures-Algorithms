#include <stdio.h>
// 数组指针
int main()
{
    int arr[] = {1 ,2 ,3 ,4 ,5};
    // 让指针p1 直接等于 arr ，此时的arr会的指针步长为数组的长度
    int* p1 = arr;
    int* p2 = &arr[0];
    printf("%p\n , %p\n" , p1 , p2);
    return 0;
}