#include <stdio.h>
#include <stdlib.h>

int Partition(int arr[], int low, int high);   // 你要实现的函数
void QuickSort(int arr[], int low, int high);  // 你要实现的函数

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
    QuickSort(a, 0, n - 1);
    printf("排序后: "); PrintArr(a, n);
    printf("预期: 13 27 38 49 65 76 97\n");

    // 最坏情况：已经有序的数组
    int b[] = {1, 2, 3, 4, 5};
    QuickSort(b, 0, 4);
    printf("有序数组: "); PrintArr(b, 5);
    printf("预期: 1 2 3 4 5\n");
    return 0;
}

int Partition(int arr[], int low, int high) {
    int pivot = arr[low];
    while (low < high) {
       while (low < high && arr[high] >= pivot) high--;
       arr[low] = arr[high];
       while (low < high && arr[low] <= pivot) low++;
       arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void QuickSort(int arr[], int low, int high) {
    if (low >= high) return;
    int num = Partition(arr, low, high);
    QuickSort(arr, num+1, high);
    QuickSort(arr, low, num-1);
    return;
}