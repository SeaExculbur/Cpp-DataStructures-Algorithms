#include <iostream>
#include <vector>

using namespace std;

vector <int> MergeList(vector <int> &L1, vector <int> &L2) {
    if (L1.empty() && L2.empty()) return vector<int>();  // 返回默认构造函数, 等价于{}
    int index1 = 0;
    int index2 = 0;
    vector <int> L3;
    while (index1 < L1.size() && index2 < L2.size())
    {
        if (L1[index1] >= L2[index2]) {
            L3.push_back(L2[index2]);
            index2++;
        }
        else {
            L3.push_back(L1[index1]);
            index1++;
        }
    }
    while (index1 < L1.size()) {
        L3.push_back(L1[index1]);
        index1++;
    }
    while (index2 < L2.size()) {
        L3.push_back(L2[index2]);
        index2++;
    }
    return L3;
}

void printlist(vector <int> &L) {
    if (L.empty()) {
        cout << "(空)";
    } else {
        for (int i : L) cout << i << " ";
    }
    cout << endl;
}

int main() {
    /* ---- 测试1：交替合并 ---- */
    vector<int> L1 = {1, 3, 5, 7};
    vector<int> L2 = {2, 4, 6, 8};
    cout << "L1: "; printlist(L1);
    cout << "L2: "; printlist(L2);
    vector<int> L3 = MergeList(L1, L2);
    cout << "合并: "; printlist(L3);
    cout << "预期: 1 2 3 4 5 6 7 8" << endl << endl;

    /* ---- 测试2：L1全部小于L2 ---- */
    L1 = {1, 2, 3};
    L2 = {4, 5, 6};
    cout << "L1: "; printlist(L1);
    cout << "L2: "; printlist(L2);
    L3 = MergeList(L1, L2);
    cout << "合并: "; printlist(L3);
    cout << "预期: 1 2 3 4 5 6" << endl << endl;

    /* ---- 测试3：含重复元素 ---- */
    L1 = {1, 1, 2};
    L2 = {1, 2, 3};
    cout << "L1: "; printlist(L1);
    cout << "L2: "; printlist(L2);
    L3 = MergeList(L1, L2);
    cout << "合并: "; printlist(L3);
    cout << "预期: 1 1 1 2 2 3" << endl << endl;

    /* ---- 测试4：L2为空 ---- */
    L1 = {1, 2, 3};
    L2.clear();
    cout << "L1: "; printlist(L1);
    cout << "L2(空): "; printlist(L2);
    L3 = MergeList(L1, L2);
    cout << "合并: "; printlist(L3);
    cout << "预期: 1 2 3" << endl << endl;

    /* ---- 测试5：两个都为空 ---- */
    L1.clear();
    cout << "L1(空): "; printlist(L1);
    cout << "L2(空): "; printlist(L2);
    L3 = MergeList(L1, L2);
    cout << "合并: "; printlist(L3);
    cout << "预期: (空)" << endl;

    return 0;
}