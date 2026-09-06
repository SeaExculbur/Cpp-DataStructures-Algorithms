#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode ,*LinkList;

void InitList(LinkList *L) {
    *L = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL) return;
    (*L)->next = NULL;
    (*L)->data = -1;
    return;
}

void BuildList(LinkList L, int arr[], int n) {
    if (L == NULL) return;
    LNode *s = L;
    for (int i = 0 ; i < n ; i++) {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        if (p == NULL) {
            printf("内存不足，分配失败！\n");
            return;
        }
        p->data = arr[i];
        p->next = s->next;
        s->next = p;
        s = p;
    }
    return;
}

void List_DeleteValue(LinkList L, int x) {
    if (L == NULL || L->next == NULL) {
        printf("为空表\n");
        return;
    }
    LNode *s = L;
    LNode *p = L->next;
    while (p != NULL)
    {
        if (p->data == x) {
            s->next = p->next;
            LNode *tmp = p;
            p = p->next;
            free(tmp);
        }
        else {
            s = p;
            p = p->next;
        }
    }
    
    return;
    
}

void PrintList(LinkList L) {
    if (L == NULL || L->next == NULL) {
        printf("是空表或者只有头节点！\n");
        return;
    }
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d\n" , p->data);
        p = p->next;
    }
    return;
}

void DestroyList(LinkList *L) {
    while (*L != NULL) {
        LNode *tmp = *L;
        *L = (*L)->next;
        free(tmp);
    }
    return;
}

int main() {
    int arr[] = {10, 20, 30 ,20 ,40 ,20 ,50};
    int n = sizeof(arr) / sizeof(int);
    LinkList L;
    InitList(&L);
    BuildList(L, arr ,n);
    List_DeleteValue(L ,20);
    printf("------------\n");
    PrintList(L);
    List_DeleteValue(L ,99);
    printf("------------\n");
    PrintList(L);
    List_DeleteValue(L ,10);
    printf("------------\n");
    PrintList(L);
    List_DeleteValue(L ,50);
    printf("------------\n");
    PrintList(L);
}