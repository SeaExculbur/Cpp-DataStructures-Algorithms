#include <stdio.h>
#include <stdlib.h>
#include "../../h/common.h"

// ==================== 请实现 Intersection ====================
// 功能：求两个升序顺序表的交集，返回新表
// 标签：🧱 边界  📋 初始化  💧 泄漏
//
// 简化条件：每个表内部元素各自不重复

Sqlist *Intersection(Sqlist *L1, Sqlist *L2) {
    if (L1 == NULL || L2 == NULL) {
        return NULL;
    }
    Sqlist *L =(Sqlist *)malloc(sizeof(Sqlist));
    L->data = (int *)malloc(sizeof(int) * (L1->MaxSize + L2->MaxSize));
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < L1->length && j < L2->length) {
        if (L1->data[i] > L2->data[j])
            j++;
        else if (L1->data[i] < L2->data[j])
            i++;
        else {
            L->data[count] = L1->data[i];
            i++;
            j++;
            count++;
        }
    }
    L->length = count;
    L->MaxSize = L1->MaxSize + L2->MaxSize;
    return L;
}

// ==================== 测试 ====================

int main() {
    Sqlist L1, L2;
    initlist(&L1);
    initlist(&L2);

    printf("=== 测试1：有交集 ===\n");
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 3, 5, 8};
    buildList(&L1, arr1, 4);
    buildList(&L2, arr2, 4);
    printf("L1: "); printlist(&L1);
    printf("L2: "); printlist(&L2);
    Sqlist *result = Intersection(&L1, &L2);
    printf("交集: "); printlist(result);
    printf("预期:   [3, 5]\n");
    destroyList(result);
    free(result);

    printf("\n=== 测试2：无交集 ===\n");
    int arr3[] = {1, 2, 3};
    int arr4[] = {4, 5, 6};
    buildList(&L1, arr3, 3);
    buildList(&L2, arr4, 3);
    printf("L1: "); printlist(&L1);
    printf("L2: "); printlist(&L2);
    result = Intersection(&L1, &L2);
    printf("交集: "); printlist(result);
    printf("预期:   []\n");
    destroyList(result);
    free(result);

    printf("\n=== 测试3：完全相同 ===\n");
    int arr5[] = {1, 2, 3, 4};
    int arr6[] = {1, 2, 3, 4};
    buildList(&L1, arr5, 4);
    buildList(&L2, arr6, 4);
    printf("L1: "); printlist(&L1);
    printf("L2: "); printlist(&L2);
    result = Intersection(&L1, &L2);
    printf("交集: "); printlist(result);
    printf("预期:   [1, 2, 3, 4]\n");
    destroyList(result);
    free(result);

    printf("\n=== 测试4：空表 ===\n");
    Sqlist empty;
    initlist(&empty);
    int arr7[] = {1, 2, 3};
    buildList(&L1, arr7, 3);
    printf("L1: "); printlist(&L1);
    printf("L2(空): "); printlist(&empty);
    result = Intersection(&L1, &empty);
    printf("交集: "); printlist(result);
    printf("预期:   []\n");
    destroyList(result);
    free(result);

    destroyList(&L1);
    destroyList(&L2);
    destroyList(&empty);
    return 0;
}
