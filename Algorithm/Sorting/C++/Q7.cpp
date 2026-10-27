#include <bits/stdc++.h>
#include <vector>
using namespace std;

// ========== 你要实现的函数 ==========
void CountSort(int arr[], int n) {
    if (n <= 0) return;
    vector<int> v(101, 0);
    int i = 0;
    for (int i = 0; i++ ; i < n) {
        v[arr[i]]++;
    }

    int k = 0;
    for (int j = 0; j <= 100; j++) {
        while (v[j] > 0) {
            arr[k++] = j;
            v[j]--;
        }
    }
    return;

}

// ========== 测试 ==========
int main() {
    int a[] = {4, 2, 2, 8, 3, 3, 1}, n = 7;

    cout << "排序前: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    CountSort(a, n);

    cout << "排序后: ";
    for (int x : a) cout << x << " ";
    cout << "\n预期: 1 2 2 3 3 4 8" << endl;

    int b[] = {0, 5, 0, 3, 5, 5};
    CountSort(b, 6);
    cout << "含0重复: ";
    for (int x : b) cout << x << " ";
    cout << "\n预期: 0 0 3 5 5 5" << endl;
    return 0;
}