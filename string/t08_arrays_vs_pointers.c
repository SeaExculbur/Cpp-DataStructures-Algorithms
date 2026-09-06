/*
 * 训练 8：二维字符数组 vs 指针数组（嵌套 vs 指向）
 *
 * 弱点来源：xargs 的 cmd 应该声明成 char *cmd[MAXARG]（指针数组），
 *          第一版却写成 char cmd[100]（一个字符串）。两者的差别就是本题：
 *          char a[N][M] = "字符串真的住在数组里"（嵌套）
 *          char *b[N]   = "数组里只存指针，字符串在别处"（指向）
 *
 * 任务：① 先凭直觉预测每个 printf 的输出（写在一张纸上）
 *       ② 编译运行，对照实际输出
 *       ③ 在文件末尾注释里回答三个问题（见底部）
 */
#include <stdio.h>

int main(void)
{
    /* 数组 1：二维字符数组——每个元素是 char[16]，字符串"住"在里面 */
    char w1[4][16] = {"echo", "bye", "x", "hello world"};

    /* 数组 2：指针数组——每个元素是 char*，指向别处的字符串字面量 */
    char *w2[4] = {"echo", "bye", "x", "hello world"};

    printf("sizeof(w1) = %d   (4 行 x 每行 16 字节)\n", (int)sizeof(w1));
    printf("sizeof(w2) = %d   (4 个指针 x 每指针 8 字节)\n", (int)sizeof(w2));
    printf("sizeof(w1[0]) = %d   (一行 = 16 个 char)\n", (int)sizeof(w1[0]));
    printf("sizeof(w2[0]) = %d   (一个指针)\n", (int)sizeof(w2[0]));
    printf("sizeof(w2[0]) == sizeof(char*) ? %s\n",
           sizeof(w2[0]) == sizeof(char *) ? "yes" : "no");

    printf("w1[0][0] 可写吗？");
    w1[0][0] = 'E';                    /* 合法：w1 是真正的数组，内存可写 */
    printf(" 改后 w1[0] = \"%s\"\n", w1[0]);

    printf("w1[1] 与 w1[0] 地址差 = %d 字节 (每行固定 16)\n",
           (int)((char *)w1[1] - (char *)w1[0]));
    printf("w2[1] 与 w2[0] 地址差 = %d 字节 (相邻指针)\n",
           (int)((char **)&w2[1] - (char **)&w2[0]) * (int)sizeof(char *));

    printf("w2[0] 指向的内容: \"%s\"\n", w2[0]);
    /* 注意：w2[0][0] = 'E' 会崩溃（字符串字面量是只读的）。
     * 想体验的话，取消下面一行的注释再运行（会段错误）：
     */
    /* w2[0][0] = 'E'; */

    return 0;
}

/*
 * 预期输出（64 位系统，逐字一致）：
 * sizeof(w1) = 64   (4 行 x 每行 16 字节)
 * sizeof(w2) = 32   (4 个指针 x 每指针 8 字节)
 * sizeof(w1[0]) = 16   (一行 = 16 个 char)
 * sizeof(w2[0]) = 8   (一个指针)
 * sizeof(w2[0]) == sizeof(char*) ? yes
 * w1[0][0] 可写吗？  改后 w1[0] = "Echo"
 * w1[1] 与 w1[0] 地址差 = 16 字节 (每行固定 16)
 * w2[1] 与 w2[0] 地址差 = 8 字节 (相邻指针)
 * w2[0] 指向的内容: "echo"
 *
 * 三个思考题（写在本注释末尾）：
 * 1) w1 占 64 字节而 w2 只占 32 字节——w1 的"冗余"用在哪了？
 * 2) 为什么 w1[0][0] 可以改，而 w2[0][0] 一改就崩？
 * 3) 如果把 w1 声明成 char w1[4][16]，拷贝 w1[0] 到 w1[1]
 *    需要 memmove(w1[1], w1[0], 16)；而 w2 只需 w2[1] = w2[0]。
 *    为什么指针数组的"拷贝"便宜这么多？代价是什么？
 */
