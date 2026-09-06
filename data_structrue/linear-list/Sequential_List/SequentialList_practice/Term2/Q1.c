#include <stdio.h>
#include <stdlib.h>

#define Max_Size 10

typedef struct {
    int *data;
    int MaxSize;
    int length;
} Sqlist;

void InitList(Sqlist *L , int arr[] , int len) {
    if (L == NULL) {
        printf("L为NULL，出错\n");
        return;
    }
    if (len <= 0 || arr == NULL || len > Max_Size) {
        L->data = NULL;
        L->length = 0;
        L->MaxSize = 0;
        return;
    }
    L->MaxSize = Max_Size;
    if (len < 1 || len > L->MaxSize) {
        printf("len非法\n");
        return;
    }
    L->data = (int *)malloc(sizeof(int) * Max_Size);
    if (L->data == NULL) {
        printf("内存分配失败\n");
        return;
    }
    L->length = len;
    if (len > 0 && len <= L->MaxSize){
        for (int i = 0 ; i < L->length ; i++) {
            L->data[i] = arr[i];
        }
        for (int i = L->length ;i < Max_Size ; i++) {
            L->data[i] = 0;
        }
    }
}

void ReverseList(Sqlist *L) {
    if (L == NULL || L->length == 1 || L->length == 0) {
        return;
    }
    int i = 0;
    int j = L->length - 1;
    while (i < j)
    {
        int temp;
        temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
        i++;
        j--;
    }
}

void DelList(Sqlist *L) {
    if (L == NULL) {
        return;
    }
    free(L->data);
    L->data = NULL;
    L->length = 0 ;
}

int main()
{
    Sqlist L;
    int arr[] = {1 ,2 ,3 ,4 ,5};
    int len = sizeof(arr) / sizeof(int);
    InitList(&L , arr , len);
    ReverseList(&L);
    for (int i = 0; i < L.length ; i++) {
        printf("%d\n" , L.data[i]);
    }
    DelList(&L);
    printf("----------------\n");
    int arr2[] = {1 ,2 ,3 ,4};
    int len2 = sizeof(arr2) / sizeof(int);
    InitList(&L , arr2 , len2);
    ReverseList(&L);
    for (int i = 0; i < L.length ; i++) {
        printf("%d\n" , L.data[i]);
    }
    DelList(&L);
    printf("----------------\n");
    int arr3[] = {7};
    int len3 = sizeof(arr3) / sizeof(int);
    InitList(&L , arr3 , len3);
    ReverseList(&L);
    for (int i = 0; i < L.length ; i++) {
        printf("%d\n" , L.data[i]);
    }
    DelList(&L);
    printf("----------------\n");
    int arr4[] = {};
    int len4 = sizeof(arr4) / sizeof(int);
    if (len4 == 0) {       // 这里用了一次if来判断len4是否等于0，原因是如果还是按照之前的那样传入三个参数，此时arr为空，IDE会认为存在越界的问题，报出警告，但实际上初始化函数内部就有处理，所以这里就简单处理了一下，没有进行大批重构，避免了报错。
        printf("\n");
    }
    return 0;
}