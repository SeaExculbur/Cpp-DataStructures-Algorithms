#include <iostream>
#include <vector>
using namespace std;

void ShellSort(vector<int>& v) {
    int n = (int)v.size();
    for (int gap = n / 2; gap >= 1; gap / 2) {
        for (int i = gap; i < n; i++) {
            int temp = v[i];
            int j = i - gap;
            while (j >= 0 && v[j] > temp) {
                v[j + gap] = v[j];
                j -= gap;
            }
            v[j+gap] = temp;
        }
    }
}

int main() {
    vector<int> a = {49, 38, 65, 97, 76, 13, 27};

    cout << "排序前: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    ShellSort(a);

    cout << "排序后: ";
    for (int x : a) cout << x << " ";
    cout << "\n预期: 13 27 38 49 65 76 97" << endl;

    vector<int> b = {49, 38, 65, 97, 76, 13, 27, 49};
    ShellSort(b);
    cout << "重复元素: ";
    for (int x : b) cout << x << " ";
    cout << "\n预期: 13 27 38 49 49 65 76 97" << endl;
    return 0;
}
