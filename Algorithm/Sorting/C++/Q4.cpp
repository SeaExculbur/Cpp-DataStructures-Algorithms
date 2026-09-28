#include <bits/stdc++.h>
using namespace std;

// ========== 你要实现的函数 ==========
int Partition(int arr[], int low, int high) {
    int pivot = arr[low];
    while (low > high) {
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

// ========== 测试 ==========
int main() {
    int a[] = {49, 38, 65, 97, 76, 13, 27}, n = 7;

    cout << "排序前: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    QuickSort(a, 0, n - 1);

    cout << "排序后: ";
    for (int x : a) cout << x << " ";
    cout << "\n预期: 13 27 38 49 65 76 97" << endl;

    int b[] = {1, 2, 3, 4, 5};
    QuickSort(b, 0, 4);
    cout << "有序数组: ";
    for (int x : b) cout << x << " ";
    cout << "\n预期: 1 2 3 4 5" << endl;
    return 0;
}