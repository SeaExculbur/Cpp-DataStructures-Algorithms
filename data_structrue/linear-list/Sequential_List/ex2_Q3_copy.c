#include "common.c"

// ==================== 请实现 CopyList ====================
// 功能：深拷贝顺序表，返回一个完全独立的新表
// 标签：📋 初始化  💧 泄漏

Sqlist *CopyList(Sqlist *src) {
    // TODO: 实现深拷贝
    // 提示：
    //   1. malloc 新的 Sqlist 结构体
    //   2. 设置 MaxSize 和 length（用 src 的值还是宏？想想如果 src 扩过容呢）
    //   3. malloc 新的 data 数组（容量用 MaxSize）
    //   4. 逐元素拷贝 data
    //   5. 对照结构体定义检查有没有漏字段

    return NULL;
}

// ==================== 测试 ====================

int main() {
    printf("=== 测试1：拷贝非空表 ===\n");
    Sqlist src;
    initlist(&src);
    int arr1[] = {1, 2, 3};
    buildList(&src, arr1, 3);
    printf("src: "); printlist(&src);

    Sqlist *cpy = CopyList(&src);
    printf("cpy: "); printlist(cpy);
    printf("MaxSize: src=%d  cpy=%d（预期一致）\n", src.MaxSize, cpy->MaxSize);

    printf("\n=== 测试2：修改拷贝不影响原表（深拷贝验证）===\n");
    cpy->data[0] = 99;
    printf("修改 cpy->data[0] = 99 后:\n");
    printf("src: "); printlist(&src);
    printf("cpy: "); printlist(cpy);
    printf("预期: src=[1, 2, 3](不受影响)  cpy=[99, 2, 3]\n");

    printf("\n=== 测试3：销毁拷贝不影响原表 ===\n");
    destroyList(cpy);
    free(cpy);
    printf("cpy已销毁，src: "); printlist(&src);
    printf("预期: src 仍然可用\n");

    printf("\n=== 测试4：拷贝空表 ===\n");
    Sqlist empty;
    initlist(&empty);
    cpy = CopyList(&empty);
    printf("src(空): "); printlist(&empty);
    printf("cpy:     "); printlist(cpy);
    printf("cpy->MaxSize=%d（预期=%d，空表的data也应分配了空间）\n", cpy->MaxSize, Max_length);
    destroyList(cpy);
    free(cpy);
    destroyList(&empty);

    destroyList(&src);
    return 0;
}
