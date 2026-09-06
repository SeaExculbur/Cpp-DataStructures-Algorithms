#include <stdio.h>

int Factorial(int n) {
    if (n <= 0) return 1;
    else return n * (Factorial(n-1));
}

int main() {
    printf("0! = %d（预期 1）\n", Factorial(0));
    printf("1! = %d（预期 1）\n", Factorial(1));
    printf("5! = %d（预期 120）\n", Factorial(5));
    printf("10! = %d（预期 3628800）\n", Factorial(10));
    return 0;
}