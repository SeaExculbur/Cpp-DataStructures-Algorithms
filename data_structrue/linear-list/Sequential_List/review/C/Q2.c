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

int LocateElem(Sqlist *L, int value) {
    if (L == NULL) {
        printf("为空表\n");
        return 0;
    }
    for (int i = 0 ; i < L->length ; i ++) {
        if (L->data[i] == value) {
            return i+1;
        }
    }
    return 0;
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
    initlist(&L);

    /* ---- 测试组1：多元素表 ---- */
    int arr[] = {5, 12, 8, 12, 3};
    buildList(&L, arr, 5);
    printf("测试表："); printlist(&L);
    printf("\n");

    printf("查找 12：位序=%d（预期 2）\n", LocateElem(&L, 12));
    printf("查找 8：位序=%d（预期 3）\n", LocateElem(&L, 8));
    printf("查找 3：位序=%d（预期 5）\n", LocateElem(&L, 3));
    printf("查找 99：位序=%d（预期 0）\n", LocateElem(&L, 99));

    /* ---- 测试组2：空表 ---- */
    destroyList(&L);
    initlist(&L);                     // 重置为空表
    printf("\n空表查找 5：位序=%d（预期 0）\n", LocateElem(&L, 5));

    destroyList(&L);
    return 0;
}