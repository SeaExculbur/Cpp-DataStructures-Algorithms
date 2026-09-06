/*
 * 训练 4：路径拼接（字符串"追加"模型的核心练习）
 *
 * 弱点来源：find 题拼 buf（path + "/" + 文件名）时反复出错：
 *          - 以为 memmove/写入是"追加"（其实是覆盖）
 *          - 不理解追加 = 定位到 '\0' → 在 '\0' 处覆盖写 → 新内容自带/手动补 '\0'
 *
 * 任务：实现 path_join(char *buf, int size, const char *dir, const char *name)：
 *   把 dir + "/" + name 拼成一个完整字符串放进 buf。
 *   例：dir="./a"，name="b" → buf = "./a/b"
 *
 * 要求（练习追加模型，必须按这个思路写）：
 *   ① 可以调用 strcpy 把 dir 拷进 buf（拷开头是允许的）
 *   ② 但【加斜杠和名字的部分必须手动写】：定位 buf 当前的 '\0' 位置，
 *      在 '\0' 处覆盖写入 '/'，再写入 name 的字符（含结尾 '\0'）
 *   ③ 禁止 strcat、sprintf、snprintf
 *
 * 假设：dir 不以 '/' 结尾（测试用例保证）；总长不超过 size-1（测试保证）
 *
 * 验证：编译运行，输出与文件末尾"预期输出"逐字一致。
 */
#include <stdio.h>
#include <string.h>

int path_join(char *buf, int size, const char *dir, const char *name)
{
    /* TODO：
     *   1. strcpy(buf, dir)                    —— 拷开头
     *   2. 用指针定位 buf 的 '\0'（buf + strlen(buf)）
     *   3. 在 '\0' 处写入 '/'，指针前进一步
     *   4. 把 name 逐字符拷过去（含它的 '\0'）——可用 strcpy 拷 name 到当前位置
     *   5. 返回 0 表示成功
     */
    if (strlen(dir) + strlen(name) + 2 > size) {
        printf("路径名+name大于缓冲区，无法拷贝\n");
        return -1;
    }
    strcpy(buf, dir);
    char *p = buf + strlen(buf);
    int index = 0;
    *p = '/'; p++;
    strcpy(p, name);
    return 0;
}

int main(void)
{
    char buf[64];

    path_join(buf, 64, "./a", "b");
    printf("1:[%s]\n", buf);
    printf("2: %s\n", strcmp(buf, "./a/b") == 0 ? "OK" : "FAIL");

    path_join(buf, 64, "/x", "y");
    printf("3:[%s]\n", buf);
    printf("4: %s\n", strcmp(buf, "/x/y") == 0 ? "OK" : "FAIL");

    path_join(buf, 64, ".", "file");
    printf("5:[%s]\n", buf);
    printf("6: %s\n", strcmp(buf, "./file") == 0 ? "OK" : "FAIL");

    return 0;
}

/*
 * 预期输出（逐字一致）：
 * 1:[./a/b]
 * 2: OK
 * 3:[/x/y]
 * 4: OK
 * 5:[./file]
 * 6: OK
 *
 * 各用例验证点：
 *   1~2) 常规目录拼接
 *   3~4) 根路径 "/x" 起头（结果是一个 '/' 开头）
 *   5~6) dir 是 "."（结果 "./file"）
 */
