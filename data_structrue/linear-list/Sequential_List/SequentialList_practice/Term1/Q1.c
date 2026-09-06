#include <stdio.h>
#include <stdlib.h>

#define Max_length 10
typedef struct {
    int *data;      // 指向堆上动态分配的数组
    int MaxSize;    // 当前最大容量
    int length;     // 当前实际元素个数
} Sqlist;

Sqlist *InitList(int len) {
    Sqlist *L = (Sqlist *)malloc(sizeof(Sqlist));
    if (L == NULL) {
        printf("内存申请失败\n");
        return NULL;
    }
    L->MaxSize = Max_length;
    L->length = len;
    L->data = (int *)malloc(sizeof(int) * Max_length);
    for (int i = 0; i < L->length; i++) {
        L->data[i] = i + 1;
    }
    for (int i = L->length; i < L->MaxSize; i++) {
        L->data[i] = 0;
    }
    return L;
}

/* 方案A：原地扩容，只换 data 数组，结构体不动 */
void IncreaseSize(Sqlist *L) {
    if (L == NULL) return;
    int newSize = L->MaxSize * 2;                   // 容量翻倍
    int *newData = (int *)malloc(sizeof(int) * newSize);
    for (int i = 0; i < L->length; i++)             // 拷贝旧数据
        newData[i] = L->data[i];
    for (int i = L->length; i < newSize; i++)        // 多余空位清零
        newData[i] = 0;
    free(L->data);                                   // 释放旧数组
    L->data = newData;                               // data 指向新数组
    L->MaxSize = newSize;                            // 更新容量
}

int ListInsert(Sqlist *L, int position, int value) {
    if (L == NULL) {
        printf("L为NULL\n");
        return 0;
    }
    if (position < 1 || position > L->length + 1) {
        printf("position 非法\n");
        return 0;
    }
    if (L->length == L->MaxSize) {                   // 表满 → 扩容
        IncreaseSize(L);
    }
    for (int i = L->length; i >= position; i--) {    // 元素后移（从最后一个开始）
        L->data[i] = L->data[i - 1];
    }
    L->data[position - 1] = value;                   // 插入新值
    L->length = L->length + 1;
    return 1;
}

void DestroyList(Sqlist *L) {
    if (L == NULL) return;
    free(L->data);
    free(L);
}

int main() {
    Sqlist *L = InitList(10);          // 初始化，10个元素全满
    if (L == NULL) return 1;

    printf("=== 插入前 ===\n");
    printf("length=%d, MaxSize=%d\n", L->length, L->MaxSize);
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);
    printf("\n");

    // 表已满(10==10)，插入会触发扩容，MaxSize 翻倍到 20
    int res = ListInsert(L, 1, 99);    // 在位置1插入99
    if (res == 0) return 1;

    printf("\n=== 插入后（扩容+头插）===\n");
    printf("length=%d, MaxSize=%d\n", L->length, L->MaxSize);
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);
    printf("\n");

    DestroyList(L);
    return 0;
}
