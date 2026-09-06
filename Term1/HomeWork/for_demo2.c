#include <stdio.h>
int main()
{
    for (int a = 1 ; a <= 5 ; a++)
    {
        int sum = 0;
        sum = sum + a;
    }
    /*
    上述代码逻辑：
    先定义变量a 让a=1；
    然后定义变量sum 让sum = 0；
    sum = sum+a；
    循环主体运行结束，变量sum被抛弃，从头开始重新执行循环体；
    定义变量sum = 0；
    ……
    */
    return 0;
}