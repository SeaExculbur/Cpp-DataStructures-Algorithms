#include <stdio.h>
#include <stdlib.h>

#define Max_length 10

typedef struct {
    int *data;      // 指向堆上动态分配的数组
    int MaxSize;    // 当前最大容量
    int length;     // 当前实际元素个数
} Sqlist;

// ==================== 辅助函数（已提供） ====================

/* 初始化空顺序表，初始容量 = Max_length */
void initlist(Sqlist *p) {
    p->data = (int *)malloc(sizeof(int) * Max_length);
    p->MaxSize = Max_length;
    p->length = 0;   // 空表，元素个数为 0
}

/* 扩容：将顺序表容量增加 len */
void IncreaseSize(Sqlist *p, int len) {
    int *newData = (int *)malloc(sizeof(int) * (p->MaxSize + len));
    for (int i = 0; i < p->length; i++)
        newData[i] = p->data[i];
    free(p->data);
    p->data = newData;
    p->MaxSize += len;
    // 注意：length 不变，元素个数没增加
}

/* 打印顺序表所有元素 */
void printlist(Sqlist *L) {
    printf("[");
    for (int i = 0; i < L->length; i++) {
        printf("%d", L->data[i]);
        if (i < L->length - 1) printf(", ");
    }
    printf("] (length=%d, MaxSize=%d)\n", L->length, L->MaxSize);
}

/* 释放顺序表的数据内存 */
void destroyList(Sqlist *L) {
    free(L->data);
    L->data = NULL;
    L->length = 0;
    L->MaxSize = 0;
}

// ==================== 请实现以下函数 ====================

/*
 * 在顺序表 L 的第 position 个位置插入 value
 * 位序从 1 开始
 * 若表满，先扩容（容量翻倍）
 * 成功返回 1，失败返回 0
 */
int ListInsert(Sqlist *L, int position, int value) {
    // TODO: 在此实现

    return 0;
}

// ==================== 测试主函数 ====================

int main() {
    Sqlist L;
    initlist(&L);

    printf("=== 测试1：尾插三个元素 ===\n");
    ListInsert(&L, 1, 10);
    ListInsert(&L, 2, 20);
    ListInsert(&L, 3, 30);
    printlist(&L);

    printf("\n=== 测试2：在位置2插入 99 ===\n");
    ListInsert(&L, 2, 99);
    printlist(&L);

    printf("\n=== 测试3：在位置1插入 5（头插）===\n");
    ListInsert(&L, 1, 5);
    printlist(&L);

    printf("\n=== 测试4：在位置6插入 100（position == length+1，即尾插）===\n");
    ListInsert(&L, 6, 100);
    printlist(&L);

    printf("\n=== 测试5：非法 position ===\n");
    int ret1 = ListInsert(&L, 0, 999);
    printf("position=0 返回 %d（预期 0）\n", ret1);
    int ret2 = ListInsert(&L, 99, 888);
    printf("position=99 返回 %d（预期 0）\n", ret2);
    printlist(&L);

    printf("\n=== 测试6：扩容（当前 MaxSize=%d）===\n", L.MaxSize);
    printf("连续插入 %d 个元素填满表...\n", L.MaxSize - L.length + 3);
    for (int i = 0; i < L.MaxSize - L.length + 3; i++) {
        ListInsert(&L, L.length + 1, i * 10);
    }
    printlist(&L);
    printf("注意 MaxSize 是否已翻倍\n");

    destroyList(&L);
    return 0;
}
