#include <iostream>
using namespace std;

// ========== 你要实现的函数 ==========
int Fib(int n) {
    if (n <= 0 ) return 0;
    if (n == 1) return 1;
    return Fib(n-1) + Fib(n - 2);
}

// ========== 测试 ==========
int main() {
    cout << "Fib(0) = " << Fib(0) << " (预期 0)" << endl;
    cout << "Fib(1) = " << Fib(1) << " (预期 1)" << endl;
    cout << "Fib(2) = " << Fib(2) << " (预期 1)" << endl;
    cout << "Fib(5) = " << Fib(5) << " (预期 5)" << endl;
    cout << "Fib(10) = " << Fib(10) << " (预期 55)" << endl;
    // 别测 n=50——纯递归会超时
    return 0;
}