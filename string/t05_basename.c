/*
 * 训练 5：从路径中提取文件名（尾部扫描找最后一个 '/'）
 *
 * 弱点来源：find 的 case T_FILE 需要拿"路径最后一段"和 target 比。
 *         关键认知：C 没有子串对象——返回"指向路径内部某处的指针"，
 *         从那里开始的字符串就是文件名（因为后面是 '\0'）。
 *
 * 任务：实现 const char *basename_of(const char *path)：
 *   - 返回指向 path 中"最后一个 '/' 之后"内容的指针（不修改原串）
 *   - path 没有 '/' → 返回 path 本身
 *   - path 以 '/' 结尾（如 "a/"）→ 返回指向空串的指针（最后一个 '/' 之后是空）
 *
 * 禁止：strrchr、strtok、malloc、修改原串
 * 允许：strlen、指针算术（从末尾往前扫描）
 *
 * 提示：从 path + strlen(path) 开始往前退，直到前一个字符是 '/' 或到开头。
 *      （xv6 ls.c 的 fmtname 和 find 的 basename 都是这个思路）
 *
 * 验证：编译运行，每行末尾应为 OK。
 */
#include <stdio.h>
#include <string.h>

const char *basename_of(const char *path)
{
    if (*path == 0) return path;
    /* TODO：返回指向最后一段的指针 */
    int len = strlen(path);
    const char *p = path + len;
    for (int i = len ; i > 0 ; i--) {
        if (*p == '/') return p+1;
        p--;
    }
    return path;
}

static void check(const char *path, const char *expect)
{
    const char *got = basename_of(path);
    int ok = strcmp(got, expect) == 0;
    printf("basename_of(\"%s\") = \"%s\"  期望 \"%s\"  %s\n",
           path, got, expect, ok ? "OK" : "FAIL");
}

int main(void)
{
    check("./a/b", "b");     /* 常规：取最后一段 */
    check("b", "b");         /* 没有 '/'：返回自身 */
    check("/x/y", "y");      /* 多个 '/'：取最后一个之后 */
    check("a/", "");         /* 以 '/' 结尾：最后一段为空 */
    check("", "");           /* 空串：返回自身（空）*/
    return 0;
}

/*
 * 预期输出（逐字一致）：
 * basename_of("./a/b") = "b"  期望 "b"  OK
 * basename_of("b") = "b"  期望 "b"  OK
 * basename_of("/x/y") = "y"  期望 "y"  OK
 * basename_of("a/") = ""  期望 ""  OK
 * basename_of("") = ""  期望 ""  OK
 *
 * 各用例验证点：
 *   1) 返回的指针指向原串内部，printf %s 从那里打印到 '\0'
 *   2) 无 '/' 的退化情况
 *   3) 多个 '/' 取最后一个
 *   4~5) 边界：结尾 '/' 和空串
 */
