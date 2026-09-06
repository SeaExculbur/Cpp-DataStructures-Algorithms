#include <stdio.h>
// 冒泡排序
int main()
{
    int arr[] = {6, 4, 5 ,3 ,2 ,1 ,0};
    int len = sizeof(arr) / sizeof(int);
    
    // 排序算法
    // 外层一共要进行len-1次循环
    for (int j = 0 ; j < len - 1; j++)
        {
            // 内层每循环一次，就多减一次1
            for (int i = 0 ; i < len - 1 - j ; i++)
            {
            if (arr[i] > arr[i + 1])
            // 如果i+1的元素大于i，则替换，然后i+1继续循环，否则直接i+1，继续循环
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
            }
        }
    for (int i = 0 ; i < len ; i++)
    printf("%d\n" , arr[i]);
    return 0;
}
