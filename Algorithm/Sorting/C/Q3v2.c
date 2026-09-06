#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *y;
    *y = *x;
    *x = temp;
    return;
}

void SelectSort(int arr[], int n) {
    if (n <= 0) return;
    for (int i = 0 ; i<n ; i++) {
        int min = i;
        for (int j = i+1 ; j < n ; j++) {
            if (arr[i] > arr[j]) {
                min = j;
            }
        }
        swap(&arr[i] , &arr[min]);
    }
    return;
}


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