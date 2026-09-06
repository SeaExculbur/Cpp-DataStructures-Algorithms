#include <stdio.h>
#include <stdlib.h>

#define Max_length 10
typedef struct {
    int *data;      // 指向堆上动态分配的数组
    int MaxSize;    // 当前最大容量
    int length;     // 当前实际元素个数
} Sqlist;

int InitList(Sqlist *L , int len){
    if (L == NULL || len < 1 || len > Max_length){
        printf("初始化失败\n");
        return 0;
    }
    L->length = len;
    L->data = (int *)malloc(sizeof(int) * Max_length);
    for (int i = 0 ; i < L->length ; i++){
        L->data[i] = i + 1;
    }
    return 1;
}

int ListDelete(Sqlist *L, int position, int *deletedValue){
    if (L == NULL || position < 1 || position > L->length || deletedValue == NULL){
    printf("删除失败");
    return 0;
    }
    *deletedValue = L->data[position-1];
    for (int i = position -1 ; i < L->length -1 ; i++){
        L->data[i] = L->data[i+1];
    }
    L->data[L->length -1] = 0;
    L->length = L->length -1;
    return 1;
}

int main(){
    Sqlist L;
    int res = InitList(&L, 8);
    if (res == 0){
        return -1;
    }
    for (int i = 0 ; i < L.length ; i++){
        printf("%d\n" , L.data[i]);
    }
    printf("-----------------------------\n");
    int delval;
    int res2 = ListDelete(&L, 2 , &delval);
    if (res2 == 0){
        return -1;
    }
    for (int i = 0 ; i < L.length ; i++){
        printf("%d\n" , L.data[i]);
    }
    printf("删除了：%d\n", delval);
    return 0;
}