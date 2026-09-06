/*
 * 热身2：统计出现次数
 * 返回 value 在 vector 中出现的次数
 */

#include <iostream>
#include <vector>
using namespace std;

int countOccurrences(vector<int> &v, int value) {
    if (v.empty()) return 0;
    int count = 0;
    for (int i : v) {
        if (i == value) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    cout << "3出现了" << countOccurrences(v, 3) << "次（预期2）" << endl;
    cout << "5出现了" << countOccurrences(v, 5) << "次（预期3）" << endl;
    cout << "7出现了" << countOccurrences(v, 7) << "次（预期0）" << endl;

    vector<int> empty;
    cout << "空表中5出现了" << countOccurrences(empty, 5) << "次（预期0）" << endl;

    return 0;
}