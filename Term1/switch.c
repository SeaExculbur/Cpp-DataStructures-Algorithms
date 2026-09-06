#include <stdio.h>
int main()
{

    // switch 会对()内的表达式计算结果，根据结果对case的值进行一一匹配，如果匹配到了，则运行。
    // 不要忘了后面加上break以终止运行。
    int week = 8;
    switch(week)
    // ()里的表达式的计算结果只能为 整数/字符 ，同理，case后跟的值也只能是 整数/字符 的字面量，不可以是变量。
    {
    case 1:
        printf("今天星期1\n");
        break;
    case 2:
        printf("今天星期2\n");
        break;
    case 3:
        printf("今天星期3\n");
        break;
    case 4:
        printf("今天星期4\n");
        break;
    case 5:
        printf("今天星期5\n");
        break;
    case 6:
        printf("今天星期6\n");
        break;
    case 7:
        printf("今天星期天\n");
        break;
    // 如果结果都不匹配，则执行default。
    default:
        printf("请输入正确的天数");
    // default可以写在任何地方，甚至可以省略不写。
    }


    // case穿透：
    int num1;
    switch(num1 = 2)
    {
        case 1:
        printf("1\n");
        case 2:
        printf("2\n");
        // 此时没有遇到break，他会继续执行下面的case/default语句，直到遇到break或者结束。
        case 3:
        printf("3\n");
        default:
        printf("语句结束，没有遇到break\n");
    }
    int num2;
    switch(num2 = 5)
    {
        default:
        printf("执行1");
        break;
        case 1:
        printf("执行2");
        case 2:
        printf("执行2");
        
    }
    return 0;
}