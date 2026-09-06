/*
 * 训练 1：指针遍历求长度（字符串 = 字符数组 + '\0'）
 *
 * 弱点来源：find 题里 strlen(buf) 被当循环条件用，而 read 后的 buf 没有 '\0'
 *           → strlen 越界读垃圾。根因：不理解 strlen 的遍历是靠 '\0' 停的。
 *
 * 任务：用【指针遍历】实现 my_strlen（功能同 strlen）：
 *   - 从 s 指向的第一个字符开始，每数一个字符指针前进一格
 *   - 遇到 '\0' 停止，返回数过的字符个数
 *
 * 禁止：下标写法 s[i]、调用 strlen、调用任何库函数
 * 允许：*p、p++、指针比较
 *
 * 验证：编译运行，输出与文件末尾"预期输出"逐字一致。
 */
#include <stdio.h>

int my_strlen(const char *s)
{
    if (s == NULL) return 0;
    /* TODO：用指针遍历统计字符个数 */
    int count = 0;
    while (s[count] != '\0') {
        count++;
    }
    return count;
}

int main(void)
{
    const char *tests[] = {"", "a", "hello", "hello world"};
    for (int i = 0; i < 4; i++) {
        printf("my_strlen(\"%s\") = %d\n", tests[i], my_strlen(tests[i]));
    }
    return 0;
}

/*
 * 预期输出（逐字一致）：
 * my_strlen("") = 0
 * my_strlen("a") = 1
 * my_strlen("hello") = 5
 * my_strlen("hello world") = 11
 *
 * 各用例验证点：
 *   1) 空串：循环体一次都不该执行
 *   2) 单字符
 *   3) 普通单词
 *   4) 含空格（空格不是结束符，只有 '\0' 是）
 */
