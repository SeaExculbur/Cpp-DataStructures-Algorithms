#include <stdio.h>
#include <time.h>

/* 将本地日历日期转为 time_t；正午可避免夏令时边界导致少/多一天 */
static time_t calendar_noon(int year, int month, int day)
{
    struct tm t = {0};
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    t.tm_hour = 12;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;
    return mktime(&t);
}

int main(void)
{
    int y, m, d;

    printf("时间计算器：输入一个日期，计算到今天过了多少天。\n");
    printf("请输入年 月 日（用空格分隔，例如：2000 1 1）：");

    if (scanf("%d %d %d", &y, &m, &d) != 3) {
        printf("输入格式错误。\n");
        return 1;
    }

    if (m < 1 || m > 12 || d < 1 || d > 31) {
        printf("月份或日期不合法。\n");
        return 1;
    }

    time_t t_start = calendar_noon(y, m, d);
    if (t_start == (time_t)-1) {
        printf("日期无效（例如该月没有这一天）。\n");
        return 1;
    }

    time_t t_now = time(NULL);
    if (t_now == (time_t)-1) {
        printf("无法取得当前系统时间。\n");
        return 1;
    }

    struct tm *today = localtime(&t_now);
    if (!today) {
        printf("无法解析本地时间。\n");
        return 1;
    }

    int ty = today->tm_year + 1900;
    int tm = today->tm_mon + 1;
    int td = today->tm_mday;
    time_t t_today = calendar_noon(ty, tm, td);

    double sec = difftime(t_today, t_start);
    long days = (long)(sec / 86400.0 + (sec >= 0 ? 0.5 : -0.5));

    printf("今天：%d 年 %d 月 %d 日\n", ty, tm, td);
    if (days >= 0) {
        printf("从 %d 年 %d 月 %d 日到今天，共过了 %ld 天。\n", y, m, d, days);
    } else {
        printf("该日期在未来，距离今天还有 %ld 天。\n", -days);
    }

    return 0;
}
