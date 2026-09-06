#include <stdio.h>
int main()
{
    // 下面演示 case穿透，省略代码
    int month;
    printf("请输入一个月份：\n");
    scanf("%d" , &month);

    // 判断季\n节：
    switch(month)
    {
        case 3:
        case 4:
        case 5:
        printf("此时为春季\n");
        break;
        case 6:
        case 7:
        case 8:
        printf("此时为夏季\n");
        break;
        case 9:
        case 10:
        case 11:
        printf("此时为秋季\n");
        break;
        case 12:
        case 1:
        case 2:
        printf("此时为冬季\n");
        break;
        default:
        printf("请输入正确的月份！\n");
    }
    return 0;
}