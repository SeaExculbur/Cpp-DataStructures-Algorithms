#include <stdio.h>

int main()

{
    //定义初始钱包余额
    int money = 100;
    printf("钱包初始余额为：%d\n" , money);

    /*
    对钱包进行一定次数的修改
    */
   printf("取出10元后，钱包的余额为：%d\n" , money = money - 10);

   printf("取出20.5元后，钱包的余额为：%f\n" , money - 20.5);

    return 0;
}