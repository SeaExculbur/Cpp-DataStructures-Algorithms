#include <stdio.h>
#include <stdlib.h>
#include "../../h/common.h"

#define Max_length 10

// ==================== 请实现 BinarySearch ====================
// 功能：在升序顺序表中二分查找 value，返回位序（从 1 开始），找不到返回 0
// 标签：🧱 边界  ⚖️ ==/=

int BinarySearch(Sqlist *L, int value) {
    if (L == NULL) {
        return 0;
    }
    int max = L->length - 1;
    int min = 0;
    int mid = (max + min) / 2;
    while (min <= max)
    {
        if (L->data[mid] > value) {
            max = mid - 1;
            mid = (max - min)/2 + min;
        }
        else if (L->data[mid] < value) {
            min = mid + 1;
            mid = (max - min)/2 + min;
        }
        else
        return mid + 1;
    }
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
