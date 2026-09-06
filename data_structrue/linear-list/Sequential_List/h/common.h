#ifndef SQLIST_H
#define SQLIST_H

typedef struct {
    int *data;      // 指向堆上动态分配的数组
    int MaxSize;    // 当前最大容量
    int length;     // 当前实际元素个数
} Sqlist;

void initlist(Sqlist *p);

void IncreaseSize(Sqlist *p, int len);

void printlist(Sqlist *L);

void destroyList(Sqlist *L);

void buildList(Sqlist *L, int arr[], int n);
#endif