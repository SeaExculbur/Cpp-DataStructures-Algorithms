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
    // 初始化数组值
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

void RemoveDuplicates(Sqlist *L) {
    if (L == NULL) {
        printf("L为空\n");
        return;
    }
    if (L->length == 1) return;
    int *s = L->data;
    int *f = L->data+1;
    int count = 0;
    int num = 1;
    while (num < L->length)
    {
        if (*f != *(f-1)) {
            s++;
            *s = *f;
            f++;
        }
        else {
            f++;
            count++;
        }
        num++;
    }
    L->length = L->length - count;
    return;
}

int main() {
    Sqlist L;
    initlist(&L);

    /* ---- 测试1：普通去重 ---- */
    int arr1[] = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    buildList(&L, arr1, 9);
    printf("去重前："); printlist(&L);
    RemoveDuplicates(&L);
    printf("去重后："); printlist(&L);
    printf("预期：[1, 2, 3, 4, 5]\n\n");

    /* ---- 测试2：无重复 ---- */
    int arr2[] = {1, 2, 3, 4, 5};
    buildList(&L, arr2, 5);
    printf("去重前："); printlist(&L);
    RemoveDuplicates(&L);
    printf("去重后："); printlist(&L);
    printf("预期：[1, 2, 3, 4, 5]\n\n");

    /* ---- 测试3：全重复 ---- */
    int arr3[] = {7, 7, 7, 7};
    buildList(&L, arr3, 4);
    printf("去重前："); printlist(&L);
    RemoveDuplicates(&L);
    printf("去重后："); printlist(&L);
    printf("预期：[7]\n\n");

    /* ---- 测试4：空表 ---- */
    destroyList(&L);
    initlist(&L);                     // 重置为空表
    printf("去重前："); printlist(&L);
    RemoveDuplicates(&L);
    printf("去重后："); printlist(&L);
    printf("预期：[]\n\n");

    /* ---- 测试5：另一个普通去重 ---- */
    int arr5[] = {3, 3, 5, 5, 5, 8};
    buildList(&L, arr5, 6);
    printf("去重前："); printlist(&L);
    RemoveDuplicates(&L);
    printf("去重后："); printlist(&L);
    printf("预期：[3, 5, 8]\n");

    destroyList(&L);
    return 0;
}