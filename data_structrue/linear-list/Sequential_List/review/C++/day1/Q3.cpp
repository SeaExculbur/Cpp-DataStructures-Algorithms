#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector <int> &L, int value) {
    if (L.empty()) return 0;
    int min = 0;
    int max = L.size()-1;
    int mid = min + (max - min) / 2;
    while (min <= max)
    mid = min + (max - min) / 2;
    {
        if (L[mid] > value) {
            max = mid - 1;
        }
        else if (L[mid] < value)
        {
            min = mid + 1;
        }
        else return mid+1;
    }

    return 0;
}

void printlist(vector <int> &L) {
    if (L.empty()) {
        printf("L为空\n");
        return;
    }
    cout << "L的内容为：";
    for (int i : L) cout << i << " ";
    cout << endl;
    return;
}

int main() {
    vector <int> L = {1, 3, 5, 7, 9, 11, 13};
    printlist(L);
    int ret1 = BinarySearch(L, 7);
    cout << ret1;
}