/*
 * 训练 2：实现 strcpy（拷贝到源的 '\0' 为止，并给目标补 '\0'）
 *
 * 弱点来源：xv6 里 write(&data, 4) 把指针地址当内容传；
 *          不理解 strcpy 的语义 = 边拷边前进，遇到源的 '\0' 才停，
 *          并且把 '\0' 也拷给目标（目标因此自动有结尾）。
 *
 * 任务：实现 my_strcpy(char *dst, const char *src)，语义与 strcpy 完全一致：
 *   - 从 src 逐个拷字符到 dst（包括结尾的 '\0'）
 *   - 返回 dst（原样返回第一个参数）
 *
 * 禁止：调用 strcpy/strncpy/memcpy/memmove
 * 允许：*p = *q、p++、q++（这题就是练"边拷边前进"）
 *
 * 验证：编译运行，输出与文件末尾"预期输出"逐字一致。
 */
#include <stdio.h>
#include <string.h>

char *my_strcpy(char *dst, const char *src)
{
    int lensrc = strlen(src);
    int lendst = strlen(dst);
    if (lendst < lensrc) {
        printf("dst长度小于src\n");
    }
    int i = 0;
    for (; i < lensrc ; i++) {
        if (i == lendst) {
            dst[i] = '\0';
            break;
        }
        dst[i] = src[i];
    }
    dst[i] = '\0';
    return dst;
}


int main(void)
{
    char dst[32];
    char *ret;

    /* 用例 1：目标里预先填满 '#'，验证拷完的 '\0' 挡住了后面的 '#' */
    memset(dst, '#', 31);
    dst[31] = 0;
    my_strcpy(dst, "hi");
    printf("1:[%s]\n", dst);                    /* 只应看到 hi，不能看到 # */

    /* 用例 2：拷贝后 strlen 应等于源长度（证明结尾有 '\0'） */
    my_strcpy(dst, "hello");
    printf("2: len=%d\n", (int)strlen(dst));

    /* 用例 3：返回值应等于 dst（和标准 strcpy 一致） */
    ret = my_strcpy(dst, "abc");
    printf("3: %s\n", ret == dst ? "ret==dst" : "ret!=dst");

    return 0;
}

/*
 * 预期输出（逐字一致）：
 * 1:[hi]
 * 2: len=5
 * 3: ret==dst
 *
 * 各用例验证点：
 *   1) 目标原内容 '#' 被 '\0' 挡住——拷完的目标必须以 '\0' 结尾
 *   2) strlen 能正确数出 5，证明 '\0' 就位
 *   3) 返回值 = 第一个参数（惯例，便于链式调用）
 */
