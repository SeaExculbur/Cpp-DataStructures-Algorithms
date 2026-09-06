#include <stdio.h>
#include <string.h>

#define MAX 100

long long memo[MAX];  // 缓存数组，-1 表示"还没算过"

long long Fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];           // 缓存命中，直接返回
    memo[n] = Fib(n-1) + Fib(n-2);               // 没命中，算了再存
    return memo[n];
}

int main() {
    memset(memo, -1, sizeof(memo));  // 全部初始化为 -1
    printf("Fib(50) = %lld\n", Fib(50));  // 现在秒出，不会超时
    return 0;
}
