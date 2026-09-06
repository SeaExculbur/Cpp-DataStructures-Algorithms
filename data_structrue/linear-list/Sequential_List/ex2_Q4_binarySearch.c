#include "common.c"

// ==================== 请实现 BinarySearch ====================
// 功能：在升序顺序表中二分查找 value，返回位序（从 1 开始），找不到返回 0
// 标签：🧱 边界  ⚖️ ==/=

int BinarySearch(Sqlist *L, int value) {
    // TODO: 实现二分查找
    // 提示：
    //   left = 0, right = length - 1
    //   while (left <= right) {          ← 注意：是 <= 不是 <
    //       mid = left + (right - left) / 2;   ← 这样写避免 left+right 溢出
    //       if (data[mid] == value) return mid + 1;   ← 位序 = 下标 + 1
    //       else if (data[mid] < value) left = mid + 1;
    //       else right = mid - 1;
    //   }
    //   return 0;
    // 记得处理空表！

    return 0;
}

// ==================== 测试 ====================

int main() {
    Sqlist L;
    initlist(&L);
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    buildList(&L, arr, 7);
    printf("测试表: "); printlist(&L);

    printf("\n=== 查找测试 ===\n");
    int pos;

    pos = BinarySearch(&L, 7);
    printf("查找 7:  位序=%d（预期 4）\n", pos);

    pos = BinarySearch(&L, 1);
    printf("查找 1:  位序=%d（预期 1，表头）\n", pos);

    pos = BinarySearch(&L, 13);
    printf("查找 13: 位序=%d（预期 7，表尾）\n", pos);

    pos = BinarySearch(&L, 6);
    printf("查找 6:  位序=%d（预期 0，不存在）\n", pos);

    pos = BinarySearch(&L, -1);
    printf("查找 -1: 位序=%d（预期 0，比最小值还小）\n", pos);

    pos = BinarySearch(&L, 99);
    printf("查找 99: 位序=%d（预期 0，比最大值还大）\n", pos);

    printf("\n=== 单元素表 ===\n");
    int arr2[] = {5};
    buildList(&L, arr2, 1);
    printf("测试表: "); printlist(&L);
    pos = BinarySearch(&L, 5);
    printf("查找 5: 位序=%d（预期 1）\n", pos);
    pos = BinarySearch(&L, 3);
    printf("查找 3: 位序=%d（预期 0）\n", pos);

    printf("\n=== 空表 ===\n");
    initlist(&L);
    printf("测试表: "); printlist(&L);
    pos = BinarySearch(&L, 1);
    printf("查找 1: 位序=%d（预期 0）\n", pos);

    destroyList(&L);
    return 0;
}
