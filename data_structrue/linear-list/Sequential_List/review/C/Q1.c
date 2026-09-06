#include <stdio.h>
#include <stdlib.h>

#define Max_length 10
typedef struct {
    int *data;      // 堆上动态数组
    int MaxSize;    // 当前最大容量
    int length;     // 当前实际元素个数
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

int ListDelete(Sqlist *L, int position, int *deletedValue) {
    if (L == NULL) {
        printf("顺序表为空\n");
        return 0;
    }
    if (position > L->length || position <= 0 ) {
        printf("position非法\n");
        return 0;
    }
    *deletedValue = L->data[position-1];
    for (int i = position-1 ; i < L->length-1 ; i++) {
        L->data[i] = L->data[i+1];
    }
    L->length--;
    return 1;
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

int main() {
    Sqlist L;
    int deletedValue;
    int ret;

    /* ---- 测试1：删除中间位置 ---- */
    int arr[] = {10, 20, 30, 40, 50};
    initlist(&L);
    buildList(&L, arr, 5);
    printf("初始："); printlist(&L);
    ret = ListDelete(&L, 3, &deletedValue);
    printf("删除位序3：ret=%d, 被删值=%d, 表：", ret, deletedValue);
    printlist(&L);
    printf("预期：ret=1, 被删值=30, 表：[10, 20, 40, 50]\n\n");

    /* ---- 测试2：头删 ---- */
    ret = ListDelete(&L, 1, &deletedValue);
    printf("删除位序1：ret=%d, 被删值=%d, 表：", ret, deletedValue);
    printlist(&L);
    printf("预期：ret=1, 被删值=10, 表：[20, 40, 50]\n\n");

    /* ---- 测试3：尾删 ---- */
    ret = ListDelete(&L, 3, &deletedValue);
    printf("删除位序3：ret=%d, 被删值=%d, 表：", ret, deletedValue);
    printlist(&L);
    printf("预期：ret=1, 被删值=50, 表：[20, 40]\n\n");

    /* ---- 测试4：空表删除 ---- */
    destroyList(&L);
    initlist(&L);                     // 重置为空表
    ret = ListDelete(&L, 1, &deletedValue);
    printf("空表删除位序1：ret=%d\n", ret);
    printf("预期：ret=0\n\n");

    /* ---- 测试5：删除位序0（非法） ---- */
    int arr2[] = {10, 20, 30};
    buildList(&L, arr2, 3);
    ret = ListDelete(&L, 0, &deletedValue);
    printf("删除位序0：ret=%d\n", ret);
    printf("预期：ret=0\n\n");

    /* ---- 测试6：删除位序99（超表长） ---- */
    ret = ListDelete(&L, 99, &deletedValue);
    printf("删除位序99：ret=%d\n", ret);
    printf("预期：ret=0\n");

    destroyList(&L);
    return 0;
}