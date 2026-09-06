#include <stdio.h>

int Fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return Fib(n-1) + Fib(n - 2);
}

int main() {
    printf("Fib(0) = %d（预期 0）\n", Fib(0));
    printf("Fib(1) = %d（预期 1）\n", Fib(1));
    printf("Fib(2) = %d（预期 1）\n", Fib(2));
    printf("Fib(5) = %d（预期 5）\n", Fib(5));
    printf("Fib(10) = %d（预期 55）\n", Fib(10));
    // 别测 n=50——纯递归会超时（原因后面再讲）
    return 0;
}