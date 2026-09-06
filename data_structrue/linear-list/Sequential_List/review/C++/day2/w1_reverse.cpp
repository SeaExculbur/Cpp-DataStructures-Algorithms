/*
 * 热身1：反转 vector
 * 用双指针原地反转，不新建 vector，不调 reverse()
 */

#include <iostream>
#include <vector>
using namespace std;

void myReverse(vector<int> &v) {
    int tmp;
    int left = 0;
    int right = v.size() - 1;
    while (left < right)
    {
        tmp = v[left];
        v[left] = v[right];
        v[right] = tmp;
        left++;
        right--;
    }
    return;
}

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5};
    myReverse(v1);
    // 预期：5 4 3 2 1
    for (int x : v1) cout << x << " ";
    cout << endl;

    vector<int> v2 = {7};
    myReverse(v2);
    // 预期：7
    for (int x : v2) cout << x << " ";
    cout << endl;

    vector<int> v3 = {};
    myReverse(v3);
    // 预期：（空）
    if (v3.empty()) cout << "(空)";
    cout << endl;

    return 0;
}