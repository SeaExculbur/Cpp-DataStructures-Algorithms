/*
 * 热身3：sort 排序
 * <algorithm> 里的 sort() 一行替代手写冒泡/快排
 *
 * sort(v.begin(), v.end())           升序
 * sort(v.begin(), v.end(), greater<int>())  降序
 */

#include <iostream>
#include <vector>
#include <algorithm>      // sort 在这里
using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    sort(v.begin(), v.end());
    cout << "升序: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    // 预期：1 1 2 3 3 4 5 5 5 6 9

    sort(v.begin(), v.end(), greater<int>());
    cout << "降序: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    // 预期：9 6 5 5 5 4 3 3 2 1 1

    return 0;
}