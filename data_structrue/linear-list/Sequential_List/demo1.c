#include <stdio.h>
#include <stdlib.h>

#define Max_length 10
typedef struct{
    int length;
    int arr[Max_length];
}Sqlist;

void initlist(Sqlist *p){
    for (int i = 0 ; i < Max_length ; i++)
        p->arr[i] = 0;
    p->length = 0;
}

int main(){
    Sqlist L;
    initlist(&L);
    for (int i = 0 ; i < Max_length ; i++){
        printf("%d\n" , L.arr[i]);
    }
    return 0;
}

