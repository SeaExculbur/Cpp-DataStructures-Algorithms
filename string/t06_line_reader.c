/*
 * 训练 6：逐行读取（累积游标 + EOF 尾行处理）
 *
 * 弱点来源：xargs 读 stdin 时的两个错误理解：
 *          - "n 是不是每轮循环都等于 0？"（n 是累积游标，只在行结束时重置）
 *          - "read 返回 0 不就代表读完了吗，为什么 EOF 后还要再处理一次？"
 *            （'\n' 是行结束标记，EOF 是输入结束标记——最后一行可能没有 '\n'）
 *
 * 任务：在 main 里实现"逐字符读 stdin，按行切分"：
 *   - 用 fgetc(stdin) 逐字符读（它和 read 一样一次给一个字符）
 *   - 每读到一行（以 '\n' 结束）→ 把行变成字符串（补 '\0'）→ 调 handle_line
 *   - 读完一行后重置游标 n = 0
 *   - 循环结束后：如果还有未处理的行（EOF 前没有 '\n' 的残余）→ 也要补 '\0' 并处理
 *   - 行缓冲最大 511 字符，超长丢弃多余字符
 *
 * 禁止：fgets、getline、scanf("%s") 等现成读行函数
 * 允许：fgetc
 *
 * 验证：编译后用管道/重定向喂三种输入（在 Git Bash 中运行）：
 *   printf "abc\n"            | ./t06_line_reader.exe   →  [abc]
 *   printf "abc\nhello"       | ./t06_line_reader.exe   →  [abc][hello]
 *   printf "abc\nhello\n"     | ./t06_line_reader.exe   →  [abc][hello]
 *   第三种和第二种输出相同（末尾 \n 不影响结果）；第二种靠的就是 EOF 尾行处理。
 */
#include <stdio.h>

/* 已给：收到一行的处理函数——你不需要改它 */
static void handle_line(char *line)
{
    printf("[%s]\n", line);
}

int main(void)
{
    char line[512];
    int n = 0;          /* 累积游标：已写入的字符数（= 下一个空位下标）*/
    int c;

    /* TODO：循环体框架如下，把逻辑补全：
     *   while ((c = fgetc(stdin)) != EOF) {
     *       if (c == '\n') { 行结束：line[n]=0 → handle_line(line) → n=0 }
     *       else if (n < 511) { line[n++] = c; }
     *       else { 超长：丢弃该字符（什么都不做）}
     *   }
     *   TODO：循环结束后，若 n > 0（EOF 前的残余行），同样补 '\0' 并处理
     */
    return 0;
}
