#include <stdio.h>

// int main()
// {
//     int a;
//     a = 10;
//     printf("%d\n" , a);
    
//     int b;
//     b = 20;
//     printf("%d\n" , b);

//     int c;
//     c = a + b;
//     printf("%d\n" , c);

//     int d;
//     printf("%d\n" , d = a + b); 
//     return 0;
// }
int main()
{
    int a = 10;

    // 对于变量的修改，就不要重新定义了，直接修改即可
    a = 100;

    printf("%d" , a);

    //一句话可以定义多个变量,但是不建议这样定义,因为不直观
    int b = 100, c = 300, d = 150;
    printf("%d", c);
    printf("%d", d);
    printf("%d", b);

    long long a1 = 10000000000ll;
    printf("%d" , a1);
    return 0;
}
