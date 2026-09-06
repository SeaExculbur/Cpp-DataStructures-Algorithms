#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void ReverseArray(vector<int> &arr) {
    if (arr.empty()) {
        cout << "arr为空" << endl;
        return;
    }

    stack<int> S;
    for (int i : arr) S.push(i);
    int j = 0;
    while (!S.empty())
    {
        arr[j] = S.top();
        S.pop();
        j++;
    }
    return;
}

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5};
    ReverseArray(v1);
    cout << "反转后: ";
    for (int x : v1) cout << x << " ";
    cout << "\n预期: 5 4 3 2 1" << endl;

    vector<int> v2 = {7};
    ReverseArray(v2);
    cout << "单元素反转: " << v2[0] << "（预期 7）" << endl;
}