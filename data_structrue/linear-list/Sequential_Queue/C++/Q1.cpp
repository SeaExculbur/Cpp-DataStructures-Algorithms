#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;

    // 1. 判空
    cout << "空队列: empty=" << q.empty() << "（预期 1）" << endl;

    // 2. 入队 10, 20, 30, 40, 50
    q.push(10); q.push(20); q.push(30); q.push(40); q.push(50);
    cout << "队头=" << q.front() << "（预期 10）" << endl;
    cout << "队尾=" << q.back() << "（预期 50）" << endl;
    cout << "size=" << q.size() << "（预期 5）" << endl;

    // 3. 出队两个
    q.pop();
    q.pop();
    cout << "出队两次后队头=" << q.front() << "（预期 30）" << endl;

    // 4. 循环出队全部
    cout << "全部出队: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n预期: 30 40 50" << endl;

    // 5. 空队出队（queue 的 pop 在空时是未定义行为，先判空！）
    cout << "空队 empty=" << q.empty() << "（预期 1）" << endl;
}