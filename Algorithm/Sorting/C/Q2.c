#include <stdio.h>

void ShellSort(int arr[], int n) {
    int group = n / 2 ;
    int k = group;
    for (int i = 0 ; i < n ; i++) {
        
    }
}

// PrintArr 自己写

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