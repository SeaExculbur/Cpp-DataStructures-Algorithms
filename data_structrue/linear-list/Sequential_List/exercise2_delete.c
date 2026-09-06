#include <stdio.h>
#include <stdlib.h>

#define Max_length 10

typedef struct {
    int *data;
    int MaxSize;
    int length;
} Sqlist;

// ==================== 辅助函数（已提供） ====================

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

/* 快速构建顺序表（用于测试），传入数组和元素个数 */
void buildList(Sqlist *L, int arr[], int n) {
    // 确保容量足够
    while (L->MaxSize < n)
        IncreaseSize(L, L->MaxSize);
    for (int i = 0; i < n; i++)
        L->data[i] = arr[i];
    L->length = n;
}

// ==================== 请实现以下函数 ====================

/*
 * 删除顺序表 L 的第 position 个元素，被删值通过 deletedValue 带出
 * 位序从 1 开始
 * 成功返回 1，失败返回 0
 */
int ListDelete(Sqlist *L, int position, int *deletedValue) {
    // TODO: 在此实现

    return 0;
}

// ==================== 测试主函数 ====================

int main() {
    Sqlist L;
    initlist(&L);
    int deleted;

    printf("=== 构建测试表 ===\n");
    int arr[] = {10, 20, 30, 40, 50};
    buildList(&L, arr, 5);
    printlist(&L);

    printf("\n=== 测试1：删除位置3（中间删）===\n");
    if (ListDelete(&L, 3, &deleted))
        printf("删除值=%d\n", deleted);
    else
        printf("删除失败\n");
    printlist(&L);

    printf("\n=== 测试2：删除位置1（头删）===\n");
    if (ListDelete(&L, 1, &deleted))
        printf("删除值=%d\n", deleted);
    else
        printf("删除失败\n");
    printlist(&L);

    printf("\n=== 测试3：删除位置3（尾删，此时 length=3）===\n");
    if (ListDelete(&L, L.length, &deleted))
        printf("删除值=%d\n", deleted);
    else
        printf("删除失败\n");
    printlist(&L);

    printf("\n=== 测试4：删除非法位置 ===\n");
    int ret1 = ListDelete(&L, 0, &deleted);
    printf("position=0 返回 %d（预期 0）\n", ret1);
    int ret2 = ListDelete(&L, 99, &deleted);
    printf("position=99 返回 %d（预期 0）\n", ret2);
    printlist(&L);

    printf("\n=== 测试5：删到空表，再尝试删除 ===\n");
    while (L.length > 0)
        ListDelete(&L, 1, &deleted);
    printf("已清空: ");
    printlist(&L);
    int ret3 = ListDelete(&L, 1, &deleted);
    printf("空表删除返回 %d（预期 0）\n", ret3);

    destroyList(&L);
    return 0;
}
