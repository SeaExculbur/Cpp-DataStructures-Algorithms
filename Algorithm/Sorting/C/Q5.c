#include <stdio.h>
#include <stdlib.h>

// 辅助数组的分配方式自己决定（局部数组/静态数组/全局数组）
void Merge(int arr[], int low, int mid, int high);    // 你要实现的函数
void MergeSort(int arr[], int low, int high);         // 你要实现的函数

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
    MergeSort(a, 0, n - 1);
    printf("排序后: "); PrintArr(a, n);
    printf("预期: 13 27 38 49 65 76 97\n");

    // 偶数个
    int b[] = {5, 2, 8, 1, 9, 3};
    MergeSort(b, 0, 5);
    printf("偶数个: "); PrintArr(b, 6);
    printf("预期: 1 2 3 5 8 9\n");
    return 0;
}

void MergeSort(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = (high + low) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid+1, high);
    Merge(arr, low, mid, high);
}

void Merge(int arr[], int low, int mid, int high) {
    int *p = (int*)malloc((high+1) * sizeof(int));
    if (p == NULL) return;
    for (int i = low ; i <= high; i++) {
        p[i] = arr[i];
    }

    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (p[i] <= p[j]) arr[k++] = p[i++];
        else arr[k++] = p[j++];
    }
    while (i <= mid) arr[k++] = p[i++];
    while (j <= high) arr[k++] = p[j++];

    free(p);
}