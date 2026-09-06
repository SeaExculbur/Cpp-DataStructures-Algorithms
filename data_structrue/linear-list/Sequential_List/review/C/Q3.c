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

int BinarySearch(Sqlist *L, int value) {
    if (L == NULL) return 0;
    int min = 0;
    int max = L->length - 1;
    int mid;
    while (min <= max) {
        mid = min + (max - min) / 2;
        if (L->data[mid] > value) {
            max = mid - 1;
        }
        else if (L->data[mid] < value) {
            min = mid + 1;
        }
        else return mid + 1;
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

    /* ---- 测试组1：7元素表 ---- */
    int arr1[] = {1, 3, 5, 7, 9, 11, 13};
    buildList(&L, arr1, 7);
    printf("测试表："); printlist(&L);
    printf("\n");

    printf("查找 7：位序=%d（预期 4）\n",   BinarySearch(&L, 7));
    printf("查找 1：位序=%d（预期 1）\n",   BinarySearch(&L, 1));
    printf("查找 13：位序=%d（预期 7）\n",  BinarySearch(&L, 13));
    printf("查找 6：位序=%d（预期 0）\n",   BinarySearch(&L, 6));
    printf("查找 -1：位序=%d（预期 0）\n",  BinarySearch(&L, -1));
    printf("查找 99：位序=%d（预期 0）\n",  BinarySearch(&L, 99));

    /* ---- 测试组2：单元素表 ---- */
    int arr2[] = {5};
    buildList(&L, arr2, 1);
    printf("\n单元素表 [5]：\n");
    printf("查找 5：位序=%d（预期 1）\n", BinarySearch(&L, 5));
    printf("查找 3：位序=%d（预期 0）\n", BinarySearch(&L, 3));

    /* ---- 测试组3：空表 ---- */
    destroyList(&L);
    initlist(&L);                     // 重置为空表
    printf("\n空表查找 1：位序=%d（预期 0）\n", BinarySearch(&L, 1));

    destroyList(&L);
    return 0;
}