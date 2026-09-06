#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> v = {10 ,20 ,30 ,40 ,50};
    v.erase(v.begin()+2);
    cout << "顺序表中的数据为：";
    for (int x : v) cout << x << " ";
    cout << endl;
    v.erase(v.begin());
    cout << "顺序表中的数据为：";
    for (int x : v) cout << x << " ";
    cout << endl;
    v.erase(v.end()-1);
    cout << "顺序表中的数据为：";
    for (int x : v) cout << x << " ";
    cout << endl;
    // 最后一步可以这么写：
    // v.popback();
    // v.end()指尾后面，v.begin()指头
    return 0;
}
