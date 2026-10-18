#include <bits/stdc++.h>
using namespace std;

// ========== 你要实现的函数 ==========
void HeapAdjust(int arr[], int k, int n) {
    int largest = k;
    int lson = 2 * k + 1;
    int rson = 2 * k + 2;

    if (lson < n && arr[largest] < arr[lson]) largest = lson;
    if (rson < n && arr[largest] < arr[rson]) largest = rson;
    if (largest != k) {
        swap(arr[largest], arr[k]);
        HeapAdjust(arr, largest, n);
    }
    return;
}

void BuildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        HeapAdjust(arr, i, n);
    return;
}

void HeapSort(int arr[], int n) {
    BuildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[i], arr[0]);
        HeapAdjust(arr, 0, i);
    }
}

// ========== 测试 ==========
int main() {
    int a[] = {53, 17, 78, 9, 45, 65, 87}, n = 7;

    cout << "排序前: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    HeapSort(a, n);

    cout << "排序后: ";
    for (int x : a) cout << x << " ";
    cout << "\n预期: 9 17 45 53 65 78 87" << endl;

    int b[] = {5};
    HeapSort(b, 1);
    cout << "单元素: " << b[0] << " (预期 5)" << endl;
    return 0;
}