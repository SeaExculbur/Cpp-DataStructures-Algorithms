#include <stdio.h>
#include <stdlib.h>

#define Max_length 10
typedef struct {
    int *data;      // 指向堆上动态分配的数组
    int MaxSize;    // 当前最大容量
    int length;     // 当前实际元素个数
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

void buildList(Sqlist *L, int arr[], int n) {
    while (L->MaxSize < n)
        IncreaseSize(L, L->MaxSize);
    for (int i = 0; i < n; i++)
        L->data[i] = arr[i];
    L->length = n;
}

int LocateElem(Sqlist *L, int value){
    if (L == NULL){
        printf("查找失败");
        return -1;
    }
    for (int i = 0; i < L->length ; i++){
        if (L->data[i] == value){
            return i+1;
        }
    }
    return 0;
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

int main(){
    Sqlist L;
    initlist(&L);
    int arr[] = {5, 12, 8, 12, 3};
    buildList(&L, arr, 5);
    printf("测试表: ");
    printlist(&L);

    printf("\n=== 查找测试 ===\n");
    int pos;

    pos = LocateElem(&L, 12);
    printf("查找 12: 位序=%d（预期 2，第一个12）\n", pos);

    pos = LocateElem(&L, 8);
    printf("查找 8:  位序=%d（预期 3）\n", pos);

    pos = LocateElem(&L, 3);
    printf("查找 3:  位序=%d（预期 5，表尾）\n", pos);

    pos = LocateElem(&L, 99);
    printf("查找 99: 位序=%d（预期 0，不存在）\n", pos);

    pos = LocateElem(&L, 5);
    printf("查找 5:  位序=%d（预期 1，表头）\n", pos);

    printf("\n=== 空表查找测试 ===\n");
    Sqlist empty;
    initlist(&empty);
    pos = LocateElem(&empty, 1);
    printf("空表查找: 位序=%d（预期 0）\n", pos);

    destroyList(&L);
    destroyList(&empty);
    system("pause");
    return 0;
}