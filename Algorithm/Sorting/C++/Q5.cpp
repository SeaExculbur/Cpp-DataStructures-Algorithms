#include <bits/stdc++.h>
#include <vector>
using namespace std;

// ========== 你要实现的函数 ==========
void Merge(int arr[], int low, int mid, int high) {
    int n = high - low + 1;
    vector<int> B(high+1);
    for (int i = low; i <= high; i++) {
        B[i] = arr[i];
    }

    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (B[i] <= B[j]) arr[k++] = B[i++];
        else arr[k++] = B[j++];
    }
    while (i <= mid) arr[k++] = B[i++];
    while (j <= high) arr[k++] = B[j++];
    return;
}

void MergeSort(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = (high + low) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, low ,mid, high);
    return;
}

// ========== 测试 ==========
int main() {
    int a[] = {49, 38, 65, 97, 76, 13, 27}, n = 7;

    cout << "排序前: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    MergeSort(a, 0, n - 1);

    cout << "排序后: ";
    for (int x : a) cout << x << " ";
    cout << "\n预期: 13 27 38 49 65 76 97" << endl;

    int b[] = {5, 2, 8, 1, 9, 3};
    MergeSort(b, 0, 5);
    cout << "偶数个: ";
    for (int x : b) cout << x << " ";
    cout << "\n预期: 1 2 3 5 8 9" << endl;
    return 0;
}