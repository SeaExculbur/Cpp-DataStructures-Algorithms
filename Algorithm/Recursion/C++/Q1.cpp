#include <iostream>
using namespace std;

// ========== 你要实现的函数 ==========
int Factorial(int n) {
    if (n < 0) return n;
    if (n == 0) return 1;
    return Factorial(n-1) * n;
}

// ========== 测试 ==========
int main() {
    cout << "0! = " << Factorial(0) << " (预期 1)" << endl;
    cout << "1! = " << Factorial(1) << " (预期 1)" << endl;
    cout << "5! = " << Factorial(5) << " (预期 120)" << endl;
    cout << "10! = " << Factorial(10) << " (预期 3628800)" << endl;
    return 0;
}