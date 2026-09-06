#include <stdio.h>
// 统计字符串中大写字符，小写字符，数字字符出现的次数
void count(char stringp[100] ,int *p_sup ,int *p_low ,int *p_num);

int main()
{
    char string[100] = "AbcDefGHIJKL12345";
    int sup = 0;
    int low = 0;
    int num = 0;
    count(string ,&sup ,&low ,&num);
    printf("%d %d %d" , sup , low , num);
}

void count(char string[100], int *p_sup ,int *p_low ,int *p_num)
{
    if (p_sup == NULL || p_low == NULL | p_num == NULL)
    {
        return;
    }
    int count_sup = 0;
    int count_low = 0;
    int count_num = 0;
    for (int i = 0 ; string[i] != '\0' ; i++)
    {
        if ('a' <= string[i] && string[i] <= 'z')
        count_low++;
        if ('A' <= string[i] && string[i] <= 'Z')
        count_sup++;
        if ('0' <= string[i] && string[i] <= '9')
        count_num++;
    }
    *p_low = count_low;
    *p_num = count_num;
    *p_sup = count_sup;
}