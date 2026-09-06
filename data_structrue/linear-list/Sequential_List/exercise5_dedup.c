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

void buildList(Sqlist *L, int arr[], int n) {
    while (L->MaxSize < n)
        IncreaseSize(L, L->MaxSize);
    for (int i = 0; i < n; i++)
        L->data[i] = arr[i];
    L->length = n;
}

// ==================== 请实现以下函数 ====================

/*
 * 对升序顺序表 L 原地去重
 * 重复元素只保留第一个，更新 length 即可，无需释放内存
 * 提示：双指针——i 遍历，j 指向已去重区末尾的下一个位置
 */
void RemoveDuplicates(Sqlist *L) {
    // TODO: 在此实现

}

// ==================== 测试主函数 ====================

int main() {
    Sqlist L;
    initlist(&L);

    printf("=== 测试1：一般去重 ===\n");
    int arr1[] = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    buildList(&L, arr1, 9);
    printf("去重前: "); printlist(&L);
    RemoveDuplicates(&L);
    printf("去重后: "); printlist(&L);
    printf("预期: [1, 2, 3, 4, 5] (length=5)\n");

    printf("\n=== 测试2：无重复 ===\n");
    int arr2[] = {1, 2, 3, 4, 5};
    buildList(&L, arr2, 5);
    printf("去重前: "); printlist(&L);
    RemoveDuplicates(&L);
    printf("去重后: "); printlist(&L);
    printf("预期: [1, 2, 3, 4, 5] (length=5，不变)\n");

    printf("\n=== 测试3：全部相同 ===\n");
    int arr3[] = {7, 7, 7, 7};
    buildList(&L, arr3, 4);
    printf("去重前: "); printlist(&L);
    RemoveDuplicates(&L);
    printf("去重后: "); printlist(&L);
    printf("预期: [7] (length=1)\n");

    printf("\n=== 测试4：空表 ===\n");
    initlist(&L);  // 重置为空表
    printf("去重前: "); printlist(&L);
    RemoveDuplicates(&L);
    printf("去重后: "); printlist(&L);
    printf("预期: [] (length=0)\n");

    printf("\n=== 测试5：另一组数据 ===\n");
    int arr5[] = {3, 3, 5, 5, 5, 8};
    buildList(&L, arr5, 6);
    printf("去重前: "); printlist(&L);
    RemoveDuplicates(&L);
    printf("去重后: "); printlist(&L);
    printf("预期: [3, 5, 8] (length=3)\n");

    destroyList(&L);
    return 0;
}
