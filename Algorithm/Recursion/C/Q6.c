#include <stdio.h>
#include <stdlib.h>

int ClimbStairs(int n);   // 你要实现的函数

int main() {
    printf("n=1: %d（预期 1）\n", ClimbStairs(1));
    printf("n=2: %d（预期 2）\n", ClimbStairs(2));
    printf("n=3: %d（预期 3）\n", ClimbStairs(3));
    printf("n=5: %d（预期 8）\n", ClimbStairs(5));
    printf("n=10: %d（预期 89）\n", ClimbStairs(10));
    return 0;
}

int ClimbStairs(int n) {
    static int memo[100] = {0};   // 只在第一次调用时全初始化为 0
    if (n <= 2) return n;
    if (memo[n] != 0) return memo[n];
    memo[n] = ClimbStairs(n-1) + ClimbStairs(n-2);
    return memo[n];
}
