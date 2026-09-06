#include <stdio.h>
#include <stdlib.h>

#define Max_length 10
typedef struct {
    int *data;
    int MaxSize;
    int length;
} Sqlist;

void initlist(Sqlist *p) {
    p->MaxSize = Max_length;
    p->length = 0;
    p->data = (int*)malloc(sizeof(int) * p->MaxSize);
    if (p->data == NULL) {
        printf("内存不足，分配失败\n");
        return;
    }
    for (int i = 0 ; i < p->length ; i ++) {
        p->data[i] = 0;
    }
    return;
}

void buildList(Sqlist *L, int arr[], int n) {
    if (n > L->MaxSize) {
        printf("数组长度过长，无法构建，退出\n");
        return;
    }
    L->length = n;
    for (int i = 0 ; i < n ; i ++) {
        L->data[i] = arr[i];
    }
    return;
}

void printlist(Sqlist *L) {
    if (L == NULL) {
        printf("L为空\n");
        return;
    }
    for (int i = 0 ; i < L->length ; i++) {
        if (i == L->length-1) {
            printf("%d\n" , L->data[i]);
            return;
        }
        printf("%d " , L->data[i]);
    }
    return;
}

void destroyList(Sqlist *L) {
    if (L == NULL) {
        printf("L为空\n");
        return;
    }
    free(L->data);
    return;
}

Sqlist *MergeList(Sqlist *L1, Sqlist *L2) {
    if (L1 == NULL && L2 != NULL) return L2;
    if (L1 != NULL && L2 == NULL) return L1;
    if (L1 == NULL && L2 == NULL) return NULL;
    int index1 = 0;
    int index2 = 0;
    // 使用动态分配保留两个原始表
    Sqlist *p3 = (Sqlist *)malloc(sizeof(Sqlist));
    if (p3 == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    p3->MaxSize = Max_length;
    if (L1->length + L2->length > p3->MaxSize) {
        printf("合并后的表长度超过L3最大值\n");
        return NULL;
    }
    p3->length = L1->length + L2->length;
    p3->data = (int *)malloc(sizeof(int) * p3->MaxSize);
    if (p3->data == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    int index3 = 0;
    while (index1 < L1->length && index2 < L2->length) {
        if (L1->data[index1] >= L2->data[index2]) {
            p3->data[index3] = L2->data[index2];
            index3++;
            index2++;
        }
        else {
            p3->data[index3] = L1->data[index1];
            index3++;
            index1++;
        }
    }
    while (index1 < L1->length) {
        p3->data[index3] = L1->data[index1];
        index3++;
        index1++;
    }
    while (index2 < L2->length) {
        p3->data[index3] = L2->data[index2];
        index3++;
        index2++;
    }
    return p3;
}

int main() {
    Sqlist L1, L2;
    initlist(&L1);
    initlist(&L2);

    /* ---- 测试1：交替合并 ---- */
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    buildList(&L1, arr1, 4);
    buildList(&L2, arr2, 4);
    printf("L1: "); printlist(&L1);
    printf("L2: "); printlist(&L2);
    Sqlist *merged = MergeList(&L1, &L2);
    printf("合并: "); printlist(merged);
    printf("预期: [1, 2, 3, 4, 5, 6, 7, 8]\n\n");
    destroyList(merged);
    free(merged);

    /* ---- 测试2：L1全部小于L2 ---- */
    int arr3[] = {1, 2, 3};
    int arr4[] = {4, 5, 6};
    buildList(&L1, arr3, 3);
    buildList(&L2, arr4, 3);
    printf("L1: "); printlist(&L1);
    printf("L2: "); printlist(&L2);
    merged = MergeList(&L1, &L2);
    printf("合并: "); printlist(merged);
    printf("预期: [1, 2, 3, 4, 5, 6]\n\n");
    destroyList(merged);
    free(merged);

    /* ---- 测试3：含重复元素 ---- */
    int arr5[] = {1, 1, 2};
    int arr6[] = {1, 2, 3};
    buildList(&L1, arr5, 3);
    buildList(&L2, arr6, 3);
    printf("L1: "); printlist(&L1);
    printf("L2: "); printlist(&L2);
    merged = MergeList(&L1, &L2);
    printf("合并: "); printlist(merged);
    printf("预期: [1, 1, 1, 2, 2, 3]\n\n");
    destroyList(merged);
    free(merged);

    /* ---- 测试4：L2为空表 ---- */
    int arr7[] = {1, 2, 3};
    buildList(&L1, arr7, 3);
    destroyList(&L2);
    initlist(&L2);                    // L2 重置为空表
    printf("L1: "); printlist(&L1);
    printf("L2(空): "); printlist(&L2);
    merged = MergeList(&L1, &L2);
    printf("合并: "); printlist(merged);
    printf("预期: [1, 2, 3]\n\n");
    destroyList(merged);
    free(merged);

    /* ---- 测试5：两个都为空表 ---- */
    destroyList(&L1); initlist(&L1);  // L1 重置为空表
    printf("L1(空): "); printlist(&L1);
    printf("L2(空): "); printlist(&L2);
    merged = MergeList(&L1, &L2);
    printf("合并: "); printlist(merged);
    printf("预期: []\n");
    destroyList(merged);
    free(merged);

    destroyList(&L1);
    destroyList(&L2);
    return 0;
}