#include <iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int>& v) {      // 传引用：直接改原容器，不拷贝
    int n = v.size();
    if (n <= 1) return;
    for (size_t i = 1; i < n; i++) {
        int temp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > temp) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = temp;
    }
    return;
}

int main() {
    vector<int> a = {49, 38, 65, 97, 76, 13, 27};   // 直接列表初始化

    cout << "排序前: ";
    for (int x : a) cout << x << " ";                // 范围 for，不用下标
    cout << endl;

    InsertSort(a);                                   // 不用传 n

    cout << "排序后: ";
    for (int x : a) cout << x << " ";
    cout << "\n预期: 13 27 38 49 65 76 97" << endl;
    return 0;
}
