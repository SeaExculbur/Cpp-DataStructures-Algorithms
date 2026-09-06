#include "common.c"

// ==================== 请实现 ReverseList ====================
// 功能：原地反转顺序表
// 标签：🧱 边界

void ReverseList(Sqlist *L) {
    // TODO: 实现原地反转
    // 提示：双指针 i=0, j=length-1，相向而行，交换元素
    // 循环终点是 i < j 或 i < length/2，两种写法等价，选你喜欢的

}

// ==================== 测试 ====================

int main() {
    Sqlist L;
    initlist(&L);

    printf("=== 测试1：奇数长度 ===\n");
    int arr1[] = {1, 2, 3, 4, 5};
    buildList(&L, arr1, 5);
    printf("反转前: "); printlist(&L);
    ReverseList(&L);
    printf("反转后: "); printlist(&L);
    printf("预期:   [5, 4, 3, 2, 1]\n");

    printf("\n=== 测试2：偶数长度 ===\n");
    int arr2[] = {1, 2, 3, 4};
    buildList(&L, arr2, 4);
    printf("反转前: "); printlist(&L);
    ReverseList(&L);
    printf("反转后: "); printlist(&L);
    printf("预期:   [4, 3, 2, 1]\n");

    printf("\n=== 测试3：单元素 ===\n");
    int arr3[] = {7};
    buildList(&L, arr3, 1);
    printf("反转前: "); printlist(&L);
    ReverseList(&L);
    printf("反转后: "); printlist(&L);
    printf("预期:   [7]\n");

    printf("\n=== 测试4：空表 ===\n");
    initlist(&L);  // 重置为空表
    printf("反转前: "); printlist(&L);
    ReverseList(&L);
    printf("反转后: "); printlist(&L);
    printf("预期:   []\n");

    destroyList(&L);
    return 0;
}
