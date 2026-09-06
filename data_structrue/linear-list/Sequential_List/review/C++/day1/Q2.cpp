#include <iostream>
#include <vector>

using namespace std;

int LocateElem(vector <int> L, int value) {
    if (L.empty()) {
        return 0;
    }
    for (int i = 0 ; i < L.size() ; i++) {
        if (L[i] == value)
        return i+1;
    }
    return 0;
}

int main() {
    vector <int> L = {5, 12, 8, 12, 3};
    int ret1 = LocateElem(L , 12);
    cout << "下标：" << ret1 << endl;
    int ret2 = LocateElem(L , 8);
    cout << "下标：" << ret2 << endl;
    int ret3 = LocateElem(L , 3);
    cout << "下标：" << ret3 << endl;
    int ret4 = LocateElem(L , 99);
    cout << "下标：" << ret4 << endl;
    vector <int> L2 = {};
    int ret5 = LocateElem(L2 , 5);
    cout << "下标：" << ret5 << endl;
    return 0;
}