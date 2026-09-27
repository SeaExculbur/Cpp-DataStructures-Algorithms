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

void HeapAdjust(int arr[], int k, int n) {   // 调整节点 k，堆大小 n
    int largest = k;                 // 假设自己最大
    int lson = 2 * k + 1;
    int rson = 2 * k + 2;

    if (lson < n && arr[largest] < arr[lson]) largest = lson;
    if (rson < n && arr[largest] < arr[rson]) largest = rson;
    if (largest != k) {
        swap(&arr[largest], &arr[k]);
        HeapAdjust(arr, largest, n); // 继续往下调整，堆大小不变
    }
}

void BuildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)   // 从最后一个非叶节点到根（含 0）
        HeapAdjust(arr, i, n);
}

void HeapSort(int arr[], int n) {
    BuildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[i], &arr[0]);     // 堆顶（最大）换到末尾
        HeapAdjust(arr, 0, i);      // 调整根，堆大小缩到 i
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
