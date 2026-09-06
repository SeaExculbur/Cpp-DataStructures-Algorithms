#include <stdio.h>
#include <stdlib.h>

#define Max_length 10
typedef struct{
    int *data;
    int MaxSize;
    int length;
}Sqlist;

void initlist(Sqlist *p){
    p->data = (int*)malloc(sizeof(int) * Max_length);
    p->length = Max_length;
    p->MaxSize = Max_length;
    for (int i = 0 ; i < Max_length ; i ++){
        p->data[i] = 0;
    }
}

void IncreaseSize(Sqlist *p , int len){
    int *ptr = p->data;
        p->MaxSize = p->MaxSize+len;
    p->data = (int*)malloc(sizeof(int) * (p->length + len));
    for (int i = 0 ; i < p->MaxSize ; i++){
        if (i < p->length)
        p->data[i] = ptr[i];
        else
        p->data[i] = 0;
    }
    p->length = p->MaxSize;
    free(ptr);
}

int main(){
    Sqlist L;
    initlist(&L);
    for (int i = 0; i < L.length ; i++){
        printf("%d\n" , L.data[i]);
    }
    IncreaseSize(&L, 10);
    for (int i = 0; i < L.length ; i++){
        printf("%d\n" , L.data[i]);
    }
    return 0;
}