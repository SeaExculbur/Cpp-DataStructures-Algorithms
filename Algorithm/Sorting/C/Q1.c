#include <stdio.h>

void InsertSort(int arr[], int n) {
    if (n <= 0) return;
    for (int i = 1 ; i < n ; i++) {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
    arr[j+1] = temp;
    }
    return;
}

// 时间复杂度: 外层 n-1 趟；第 i 趟内层执行 i 次（边找边移）
// 总操作 = 1+2+...+(n-1) = n(n-1)/2 = O(n²)
// 最好 O(n)（已有序，内层每趟只比较 1 次），最坏/平均 O(n²)

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
    InsertSort(a, n);
    printf("排序后: "); PrintArr(a, n);
    printf("预期: 13 27 38 49 65 76 97\n");

    // 边界：单元素、空数组
    int b[] = {5};
    InsertSort(b, 1);
    printf("单元素: %d（预期 5）\n", b[0]);
    return 0;
}