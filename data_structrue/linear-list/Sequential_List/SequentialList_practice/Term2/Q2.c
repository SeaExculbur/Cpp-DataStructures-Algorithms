#include "../../h/common.h"
#include <stdio.h>
#include <stdlib.h>

// ==================== 请实现 DeleteAllValue ====================
// 功能：删除顺序表中所有等于 value 的元素
// 标签：? 边界  ? 遮蔽

void DeleteAllValue(Sqlist *L, int value) {
    if (L == NULL) {
        printf("L为NULL\n");
        return;
    }
    int *ptr = (int *)malloc(sizeof(int) * L->MaxSize);
    int j = 0;
    for (int i = 0; i < L->length ; i++) {
        if (L->data[i] != value) {
            ptr[j] = L->data[i];
            j++;
        }
    }
    L->data = ptr;
    L->length = j;
}

// ==================== 测试 ====================

int main() {
    Sqlist L;
    initlist(&L);

    printf("=== 测试1：一般情况（删除2）===\n");
    int arr1[] = {1, 2, 3, 2, 4, 2, 5};
    buildList(&L, arr1, 7);
    printf("删除前: "); printlist(&L);
    DeleteAllValue(&L, 2);
    printf("删除后: "); printlist(&L);
    printf("预期:   [1, 3, 4, 5]\n");

    printf("\n=== 测试2：全部删除 ===\n");
    int arr2[] = {2, 2, 2, 2};
    buildList(&L, arr2, 4);
    printf("删除前: "); printlist(&L);
    DeleteAllValue(&L, 2);
    printf("删除后: "); printlist(&L);
    printf("预期:   []\n");

    printf("\n=== 测试3：不存在 ===\n");
    int arr3[] = {1, 3, 5};
    buildList(&L, arr3, 3);
    printf("删除前: "); printlist(&L);
    DeleteAllValue(&L, 2);
    printf("删除后: "); printlist(&L);
    printf("预期:   [1, 3, 5]（不变）\n");

    printf("\n=== 测试4：删头部 ===\n");
    int arr4[] = {1, 1, 2, 3};
    buildList(&L, arr4, 4);
    printf("删除前: "); printlist(&L);
    DeleteAllValue(&L, 1);
    printf("删除后: "); printlist(&L);
    printf("预期:   [2, 3]\n");

    printf("\n=== 测试5：删尾部 ===\n");
    int arr5[] = {1, 2, 3, 3};
    buildList(&L, arr5, 4);
    printf("删除前: "); printlist(&L);
    DeleteAllValue(&L, 3);
    printf("删除后: "); printlist(&L);
    printf("预期:   [1, 2]\n");

    printf("\n=== 测试6：空表 ===\n");
    initlist(&L);
    printf("删除前: "); printlist(&L);
    DeleteAllValue(&L, 99);
    printf("删除后: "); printlist(&L);
    printf("预期:   []\n");

    destroyList(&L);
    return 0;
}