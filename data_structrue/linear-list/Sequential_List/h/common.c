#include <stdio.h>
#include <stdlib.h>

#define Max_length 10

typedef struct {
    int *data;      // 指向堆上动态分配的数组
    int MaxSize;    // 当前最大容量
    int length;     // 当前实际元素个数
} Sqlist;

/* 初始化空顺序表，初始容量 = Max_length */
void initlist(Sqlist *p) {
    p->data = (int *)malloc(sizeof(int) * Max_length);
    p->MaxSize = Max_length;
    p->length = 0;
}

/* 原地扩容：将 data 数组容量增加 len，结构体不动 */
void IncreaseSize(Sqlist *p, int len) {
    int *newData = (int *)malloc(sizeof(int) * (p->MaxSize + len));
    for (int i = 0; i < p->length; i++)
        newData[i] = p->data[i];
    free(p->data);
    p->data = newData;
    p->MaxSize += len;
}

/* 打印顺序表，格式: [1, 2, 3] (length=3) */
void printlist(Sqlist *L) {
    printf("[");
    for (int i = 0; i < L->length; i++) {
        printf("%d", L->data[i]);
        if (i < L->length - 1) printf(", ");
    }
    printf("] (length=%d)\n", L->length);
}

/* 销毁顺序表：释放 data 和结构体自身 */
void destroyList(Sqlist *L) {
    if (L == NULL) return;
    free(L->data);
    L->data = NULL;
    L->length = 0;
    L->MaxSize = 0;
}

/* 用数组快速构建顺序表（覆盖原内容） */
void buildList(Sqlist *L, int arr[], int n) {
    while (L->MaxSize < n)
        IncreaseSize(L, L->MaxSize);
    for (int i = 0; i < n; i++)
        L->data[i] = arr[i];
    L->length = n;
}
