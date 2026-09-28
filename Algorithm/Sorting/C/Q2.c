#include <stdio.h>

void ShellSort(int arr[], int n) {
    if (n <= 1) return;
    for (int gap = n / 2 ; gap >= 1; gap /= 2) {
        for (int i = gap ; i < n ; i++) {
            int temp = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j] > temp)
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }

            arr[j + gap] = temp;
        }
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

int main() {
    int a[] = {49, 38, 65, 97, 76, 13, 27};
    int n = 7;
    printf("排序前: "); PrintArr(a, n);
    ShellSort(a, n);
    printf("排序后: "); PrintArr(a, n);
    printf("预期: 13 27 38 49 65 76 97\n");

    // 带重复元素（体验不稳定性）
    int b[] = {49, 38, 65, 97, 76, 13, 27, 49};
    ShellSort(b, 8);
    printf("重复元素: "); PrintArr(b, 8);
    printf("预期: 13 27 38 49 49 65 76 97\n");
    return 0;
}
