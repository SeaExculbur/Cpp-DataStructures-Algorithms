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

LNode* List_FindKthFromEnd(LinkList L, int k) {
    if (L == NULL || L->next == NULL) return NULL;
    if (k <=0 ) {
        printf("非法输入！\n");
        return NULL;
    }
    LNode *p = L->next;
    int num = 1;
    while (p->next != NULL)
    {
        num++;
        p = p->next;
    }
    int index = num - k;
    if (index < 0) {
        printf("超出长度限制\n");
        return NULL;
    }
    p = L->next;
    for (int i = 0; i < index ; i++) {
        p = p->next;
    }
    return p;
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
    LinkList L;
    InitList(&L);
    int arr[] = {10 ,20 ,30 ,40 ,50};
    int n = sizeof(arr) / sizeof(int);
    BuildList(L, arr ,n);
    PrintList(L);
    LNode *p1 = List_FindKthFromEnd(L ,1);
    printf("---------------\n");
    if (p1 != NULL) 
    printf("%d\n" , p1->data);
    LNode *p2 = List_FindKthFromEnd(L ,3);
    if (p2 != NULL) 
    printf("%d\n" , p2->data);
    LNode *p3 = List_FindKthFromEnd(L ,5);
    if (p3 != NULL) 
    printf("%d\n" , p3->data);
    LNode *p4 = List_FindKthFromEnd(L ,6);
    if (p4 != NULL) 
    printf("%d\n" , p4->data);
    LNode *p5 = List_FindKthFromEnd(L ,0);
    if (p5 != NULL) 
    printf("%d\n" , p5->data);
    return 0;
}