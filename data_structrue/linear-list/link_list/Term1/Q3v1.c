#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

void InitList(LinkList *L) {
    (*L) = (LNode *)malloc(sizeof(LNode));
    if (L == NULL) {
        return;
    }
    (*L)->next = NULL;
    (*L)->data = -1;
    return;
}

void BuildList(LinkList L, int arr[], int n) {
    if (L == NULL) return;
    LNode *p = L;
    for (int i = 0; i <n ; i++) {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        if (s == NULL) {
            printf("内存不足，节点分配失败！\n");
            return;
        }
        s->data = arr[i];
        s->next = NULL;
        p->next = s;
        p = s;
    }
    return;
}

void List_Reverse(LinkList L) {
    if (L == NULL || L->next == NULL || L->next->next == NULL) return;
    LNode *p = L->next;
    LNode *c = p->next;
    p->next = NULL;
    while (c->next != NULL)
    {
        LNode *n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    c->next = p;
    L->next = c;
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
    int arr[] = {10, 20, 30 ,40};
    int n = sizeof(arr) / sizeof(int);
    LinkList L;
    InitList(&L);
    BuildList(L, arr ,n);
    PrintList(L);
    List_Reverse(L);
    printf("--------------------\n");
    PrintList(L);
    return 0;
}