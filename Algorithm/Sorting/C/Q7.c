#include <stdio.h>
#include <stdlib.h>
void CountSort(int arr[], int n);   // 你要实现的函数（元素范围 0~100）
void PrintArr(int arr[], int n);

int main() {
    int a[] = {4, 2, 2, 8, 3, 3, 1};
    int n = 7;
    printf("排序前: "); PrintArr(a, n);
    CountSort(a, n);
    printf("排序后: "); PrintArr(a, n);
    printf("预期: 1 2 2 3 3 4 8\n");

    // 带 0 和重复
    int b[] = {0, 5, 0, 3, 5, 5};
    CountSort(b, 6);
    printf("含0重复: "); PrintArr(b, 6);
    printf("预期: 0 0 3 5 5 5\n");
    return 0;
}

void PrintArr(int arr[], int n) {
    if (n <= 0) return;
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", arr[i]);
    }
    return;
}

void CountSort(int arr[], int n) {
    if (n <= 1) return;
    int *p = (int*)malloc(101 * sizeof(int));
    if (p == NULL) return;
    for (int i = 0; i < 101 ; i++) {
        p[i] = 0;
    }
    int i = 0;
    
    while (i < n) {
        p[arr[i]]++;
        i++;
    }

    int k = 0;
    for (int j = 0 ;j <= 100; j++) {
        while (p[j] >= 1) {
            arr[k++] = j;
            p[j]--;
        }
    }
    free(p);
    return;
}