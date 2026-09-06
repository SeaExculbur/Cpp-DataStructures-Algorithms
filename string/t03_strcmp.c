/*
 * 训练 3：实现 strcmp（两个指针同步遍历，逐字符比较）
 *
 * 弱点来源：find 里 strcmp 比较文件名；不理解它内部是
 *          "两个指针从当前位置开始同步前进，比到第一个不同或某个 '\0' 停"。
 *          理解这一点，才明白"指针移到路径中间 = 从那里开始比"。
 *
 * 任务：实现 my_strcmp(const char *a, const char *b)：
 *   - 从 a、b 指向的位置开始逐字符比较
 *   - 相同则两指针一起前进；直到字符不同，或某方到 '\0'
 *   - 返回 (unsigned char)*a - (unsigned char)*b（符号与标准 strcmp 一致即可）
 *     即：完全相等返回 0；a 的字符更大返回正数；b 更大返回负数
 *
 * 禁止：调用 strcmp
 * 允许：*a、*b、a++、b++、指针比较
 *
 * 验证：编译运行，每一行末尾应为 OK（内部与标准 strcmp 逐对比对符号）。
 */
#include <stdio.h>
#include <string.h>

int my_strcmp(const char *a, const char *b)
{
    /* TODO：同步遍历比较 */
    while (*a != 0 && *b != 0) {
        if (*a == *b) {
            a++;b++;
        }
        else if (*a < *b) {
            return -1;
        }
        else return 1;
    }
    if (*a && !*b) return 1;
    else if (!*a && *b) return -1;
    else return 0;
}

/* 检查函数：你的结果 vs 标准 strcmp，符号一致才算过 */
static void check(const char *a, const char *b)
{
    int m = my_strcmp(a, b);
    int s = strcmp(a, b);
    int same = ((m == 0) == (s == 0)) &&
               ((m < 0) == (s < 0)) &&
               ((m > 0) == (s > 0));
    printf("\"%s\" vs \"%s\": my=%d std=%d  %s\n", a, b, m, s,
           same ? "OK" : "FAIL");
}

int main(void)
{
    check("abc", "abc");     /* 完全相等 → 0 */
    check("abc", "abd");     /* 第 3 字符 c(99) vs d(100) → 负数 */
    check("abd", "abc");     /* 反过来 → 正数 */
    check("abc", "ab");      /* 长串比短串大（'c' vs '\0'）→ 正数 */
    check("ab", "abc");      /* 短串小 → 负数 */
    check("", "a");          /* 空串最小 → 负数 */
    check("A", "a");         /* 大小写按 ASCII：'A'(65) < 'a'(97) → 负数 */
    return 0;
}

/*
 * 预期输出：7 行，每行末尾均为 OK（中间的 my=/std= 数值不重要，符号一致即可）
 *
 * 各用例验证点：
 *   1) 相等：两指针一路同步到双双 '\0'
 *   2~3) 字符不同即停，返回差值符号
 *   4~5) 一方先到 '\0'：比较 '\0'(0) 与剩余字符
 *   6) 空串参与比较
 *   7) ASCII 码大小写
 */
