#include <bits/stdc++.h>
using namespace std;

// ========== 你要实现的函数 ==========
void SelectSort(vector<int>& v) {   // 传引用，不用传 n
    int n = (int)v.size();
    if (n <= 1) return;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (v[i] > v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    return;
}

// ========== 测试 ==========
int main() {
    vector<int> a = {49, 38, 65, 97, 76, 13, 27};

    cout << "排序前: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    SelectSort(a);

    cout << "排序后: ";
    for (int x : a) cout << x << " ";
    cout << "\n预期: 13 27 38 49 65 76 97" << endl;

    vector<int> b = {2, 2, 1};
    SelectSort(b);
    cout << "重复元素: ";
    for (int x : b) cout << x << " ";
    cout << "\n预期: 1 2 2" << endl;
    return 0;
}