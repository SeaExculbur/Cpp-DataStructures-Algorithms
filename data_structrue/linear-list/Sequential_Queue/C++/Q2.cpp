#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void ReverseFirstK(vector<int> &arr, int k) {
    if (arr.empty()) {
        cout << "向量为空" << endl;
        return;
    }

    stack<int> S;
    for (int i = 0 ; i < k ; i++) {
        S.push(arr[i]);
    }
    int index = 0;
    while (!S.empty())
    {
        int res = S.top();
        S.pop();
        arr[index] = res;
        index++;
    }
    return;
    
}

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5};
    ReverseFirstK(v1, 3);
    cout << "反转前3个: ";
    for (int x : v1) cout << x << " ";
    cout << "\n预期: 3 2 1 4 5" << endl;

    vector<int> v2 = {10, 20, 30, 40};
    ReverseFirstK(v2, 4);
    cout << "反转全部: ";
    for (int x : v2) cout << x << " ";
    cout << "\n预期: 40 30 20 10" << endl;

    vector<int> v3 = {7, 8, 9};
    ReverseFirstK(v3, 1);
    cout << "k=1（不变）: ";
    for (int x : v3) cout << x << " ";
    cout << "\n预期: 7 8 9" << endl;
}