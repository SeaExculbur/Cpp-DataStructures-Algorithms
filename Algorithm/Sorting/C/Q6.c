#include <stdio.h>
#include <stdlib.h>
// 用 0 基数组实现（左孩子 = 2*i+1，右孩子 = 2*i+2）
void HeapAdjust(int arr[], int k, int n);
void BuildMaxHeap(int arr[], int n);
void HeapSort(int arr[], int n);
void swap(int *p1, int *p2);
void PrintArr(int arr[] , int n);

int main() {
    int a[] = {53, 17, 78, 9, 45, 65, 87};
    int n = 7;
    printf("排序前: "); PrintArr(a, n);
    HeapSort(a, n);
    printf("排序后: "); PrintArr(a, n);
    printf("预期: 9 17 45 53 65 78 87\n");

    // 空/单元素
    int b[] = {5};
    HeapSort(b, 1);
    printf("单元素: %d（预期 5）\n", b[0]);
    return 0;
}

void swap(int *p1, int *p2) {
    if (p1 == NULL && p2 == NULL) return;
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}

void BuildMaxHeap(int arr[], int n) {
    if (n <= 0) return;
    int i;
    for (i = n / 2 - 1; i > 0  ; i--) {
        HeapAdjust(arr, n ,i);
    }
}

void HeapAdjust(int arr[], int k, int n) {
    int largest = n;
    int lson = n * 2 + 1;
    int rson = n * 2 + 2;

    if (lson < n && arr[largest] < arr[lson]) largest = lson;
    if (lson < n && arr[largest] < arr[rson]) largest = rson;
    if (largest != n) {
        swap(&arr[largest], &arr[n]);
        HeapAdjust(arr, k, largest);
    }
    return;
}

void HeapSort(int arr[], int n) {
    BuildMaxHeap(arr, n);
    for (int i = n -1 ; i > 0 ; i--) {
        swap(&arr[i], &arr[0]);
        HeapAdjust(arr, i, 0);
    }
}

void PrintArr(int arr[] , int n) {
    if (n <= 0) return;
    for (int i = 0 ; i < n ; i ++) {
        printf("%d " , arr[i]);
    }
    printf("\n");
    return;
}
