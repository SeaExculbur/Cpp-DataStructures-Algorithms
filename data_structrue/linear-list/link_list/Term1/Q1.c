#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

void InitList(LinkList *L) {
    (*L) = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL) {
        return;
    }
    (*L)->next = NULL;
    (*L)->data = -1;
    return;
}

void List_HeadInsert(LinkList L) {
    if (L == NULL) {
        return;
    }
    printf("输入要插入的数据，输入9999结束循环\n");
    LNode *p = L;
    int num;
    scanf("%d" , &num);
    while (num != 9999)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        if (s == NULL) return;
        s->data = num;
        s->next = p->next;
        p->next = s;
        scanf("%d" , &num);
    }
    return;
}

void PrintList(LinkList L) {
    LNode *p = L->next;
    if (p == NULL) {
        printf("是空表! \n");
        return;
    }
    while (p != NULL)
    {
        printf("%d\n" , p->data);
        p = p->next;
    }
    return;
}

void DestroyList(LinkList *L) {
    while (*L != NULL)
    {
        LNode *p = *L;
        (*L) = (*L)->next;
        free(p);
    }
    return;
}

int main() {
    LinkList L;
    InitList(&L);
    List_HeadInsert(L);
    PrintList(L);
    DestroyList(&L);
    return 0;
}