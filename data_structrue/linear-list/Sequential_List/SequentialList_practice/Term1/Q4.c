#include <stdio.h>
#include <stdlib.h>

#define Max_length 10

typedef struct {
    int *data;
    int MaxSize;
    int length;
} Sqlist;

void initlist(Sqlist *p) {
    p->data = (int *)malloc(sizeof(int) * Max_length);
    p->MaxSize = Max_length;
    p->length = 0;
}

void IncreaseSize(Sqlist *p, int len) {
    int *newData = (int *)malloc(sizeof(int) * (p->MaxSize + len));
    for (int i = 0; i < p->length; i++)
        newData[i] = p->data[i];
    free(p->data);
    p->data = newData;
    p->MaxSize += len;
}

void printlist(Sqlist *L) {
    printf("[");
    for (int i = 0; i < L->length; i++) {
        printf("%d", L->data[i]);
        if (i < L->length - 1) printf(", ");
    }
    printf("] (length=%d)\n", L->length);
}

void destroyList(Sqlist *L) {
    free(L->data);
    L->data = NULL;
    L->length = 0;
    L->MaxSize = 0;
}

void buildList(Sqlist *L, int arr[], int n) {
    while (L->MaxSize < n)
        IncreaseSize(L, L->MaxSize);
    for (int i = 0; i < n; i++)
        L->data[i] = arr[i];
    L->length = n;
}

// ==================== 请实现以下函数 ====================

/*
 * 合并两个升序顺序表 L1 和 L2，返回一个新的升序顺序表
 * 新表在堆上分配，原表 L1、L2 保持不变
 * 使用双指针归并算法，时间复杂度 O(n1 + n2)
 */
Sqlist *MergeList(Sqlist *L1, Sqlist *L2){
    Sqlist *L3 = (Sqlist *)malloc(sizeof(Sqlist));
    initlist(L3);
    L3->length = L1->length + L2->length;
    while (L3->MaxSize < L3->length)        
    IncreaseSize(L3, L3->MaxSize);

    int i = 0 , j = 0 , k = 0 ;
    while (i < L1->length && j < L2->length){
            if (L1->data[i] <= L2->data[j]){
                L3->data[k] = L1->data[i];
                i++;
                k++;
            }
            else{
                L3->data[k] = L2->data[j];
                j++;
                k++;
            }
        }
    while (i < L1->length){
        L3->data[k] = L1->data[i];
        i++;
        k++;
    }
    while (j < L2->length){
        L3->data[k] = L2->data[j];
        j++;
        k++;
    }
    return L3;
}

int main() {
    Sqlist L1, L2;
    initlist(&L1);
    initlist(&L2);

    printf("=== 测试1：交替合并 ===\n");
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    buildList(&L1, arr1, 4);
    buildList(&L2, arr2, 4);
    printf("L1: "); printlist(&L1);
    printf("L2: "); printlist(&L2);
    Sqlist *merged = MergeList(&L1, &L2);
    printf("合并: "); printlist(merged);
    destroyList(merged);
    free(merged);

    printf("\n=== 测试2：L1全部小于L2 ===\n");
    int arr3[] = {1, 2, 3};
    int arr4[] = {4, 5, 6};
    buildList(&L1, arr3, 3);
    buildList(&L2, arr4, 3);
    printf("L1: "); printlist(&L1);
    printf("L2: "); printlist(&L2);
    merged = MergeList(&L1, &L2);
    printf("合并: "); printlist(merged);
    destroyList(merged);
    free(merged);

    printf("\n=== 测试3：含重复元素 ===\n");
    int arr5[] = {1, 1, 2};
    int arr6[] = {1, 2, 3};
    buildList(&L1, arr5, 3);
    buildList(&L2, arr6, 3);
    printf("L1: "); printlist(&L1);
    printf("L2: "); printlist(&L2);
    merged = MergeList(&L1, &L2);
    printf("合并: "); printlist(merged);
    destroyList(merged);
    free(merged);

    printf("\n=== 测试4：空表合并 ===\n");
    Sqlist empty;
    initlist(&empty);
    int arr7[] = {1, 2, 3};
    buildList(&L1, arr7, 3);
    printf("L1: "); printlist(&L1);
    printf("L2(空): "); printlist(&empty);
    merged = MergeList(&L1, &empty);
    printf("合并: "); printlist(merged);
    destroyList(merged);
    free(merged);

    destroyList(&L1);
    destroyList(&L2);
    destroyList(&empty);
    return 0;
}