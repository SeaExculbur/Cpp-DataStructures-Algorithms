#include <iostream>
#include <vector>

using namespace std;

void RemoveDuplicates(vector<int> &L) {
    if (L.empty()) {
        cout << "L为空" << endl;
        return;
    }
    int slow = 0;
    for (int fast = 1 ; fast < L.size() ; fast++) {
        if (L[fast] != L[fast-1]) {
            slow++;
            L[slow] = L[fast];
        }
    }
    L.resize(slow+1);
    return;
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
    vector<int> L;

    /* ---- 测试1：普通去重 ---- */
    L = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    cout << "去重前: "; printlist(L);
    RemoveDuplicates(L);
    cout << "去重后: "; printlist(L);
    cout << "预期: 1 2 3 4 5" << endl << endl;

    /* ---- 测试2：无重复 ---- */
    L = {1, 2, 3, 4, 5};
    cout << "去重前: "; printlist(L);
    RemoveDuplicates(L);
    cout << "去重后: "; printlist(L);
    cout << "预期: 1 2 3 4 5" << endl << endl;

    /* ---- 测试3：全重复 ---- */
    L = {7, 7, 7, 7};
    cout << "去重前: "; printlist(L);
    RemoveDuplicates(L);
    cout << "去重后: "; printlist(L);
    cout << "预期: 7" << endl << endl;

    /* ---- 测试4：空表 ---- */
    L.clear();
    cout << "去重前: "; printlist(L);
    RemoveDuplicates(L);
    cout << "去重后: "; printlist(L);
    cout << "预期: (空)" << endl << endl;

    /* ---- 测试5：另一个普通去重 ---- */
    L = {3, 3, 5, 5, 5, 8};
    cout << "去重前: "; printlist(L);
    RemoveDuplicates(L);
    cout << "去重后: "; printlist(L);
    cout << "预期: 3 5 8" << endl;

    return 0;
}

