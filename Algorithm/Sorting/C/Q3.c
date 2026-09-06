#include <stdio.h>

void SelectSort(int arr[], int n) {
    if (n <= 0) return;
    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return;
}

// 变体版：第 i 趟比较 n-1-i 次（递减），最坏每趟交换同样次数
// 总比较 = (n-1)+(n-2)+...+1 = n(n-1)/2 = O(n²)
// 交换最坏同量级 O(n²)（标准版一趟只交换一次，交换 O(n)）


void PrintArr(int arr[] , int n) {
    if (n <= 0) return;
    for (int i = 0 ; i < n ; i ++) {
        printf("%d " , arr[i]);
    }
    printf("\n");
    return;
}

int main() {
    int a[] = {49, 38, 65, 97, 76, 13, 27};
    int n = 7;
    printf("排序前: "); PrintArr(a, n);
    SelectSort(a, n);
    printf("排序后: "); PrintArr(a, n);
    printf("预期: 13 27 38 49 65 76 97\n");

    // 不稳定性体验：{2, 2, 1} 排序后是 {1, 2, 2}，但两个 2 的相对位置可能翻转
    int b[] = {2, 2, 1};
    SelectSort(b, 3);
    printf("重复元素: "); PrintArr(b, 3);
    printf("预期: 1 2 2\n");
    return 0;
}