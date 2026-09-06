#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // 1. 判空
    cout << "空栈: empty=" << s.empty() << "（预期 1）" << endl;

    // 2. 入栈 10, 20, 30
    s.push(10); s.push(20); s.push(30);
    cout << "栈顶=" << s.top() << "（预期 30）" << endl;
    cout << "size=" << s.size() << "（预期 3）" << endl;

    // 3. 出栈一个
    s.pop();
    cout << "出栈后栈顶=" << s.top() << "（预期 20）" << endl;

    // 4. 全出
    s.pop(); s.pop();
    cout << "全出后 empty=" << s.empty() << "（预期 1）" << endl;
     
}