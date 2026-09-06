#include <iostream>
#include <vector>
using namespace std;

// ========== 你要实现的函数 ==========
int ClimbStairs(int n) {
    if (n <= 0) return n;
    if (n == 1) return 1;
    if (n == 2) return 2;
    static vector<int> memo(100, -1);
    if (memo[n] == -1) {
        memo[n] = ClimbStairs(n-1) + ClimbStairs(n-2);
        return memo[n];
    }
    else return memo[n];
}

// ========== 测试 ==========
int main() {
    cout << "n=1: " << ClimbStairs(1) << " (预期 1)" << endl;
    cout << "n=2: " << ClimbStairs(2) << " (预期 2)" << endl;
    cout << "n=3: " << ClimbStairs(3) << " (预期 3)" << endl;
    cout << "n=5: " << ClimbStairs(5) << " (预期 8)" << endl;
    cout << "n=10: " << ClimbStairs(10) << " (预期 89)" << endl;
    return 0;
}