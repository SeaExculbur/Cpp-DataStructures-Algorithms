#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

void InitList(LinkList *L) {
    (*L) = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL) {
        printf("内存不足，节点分配失败\n");
        return;
    }
    (*L)->next = NULL;
    (*L)->data = -1;
}

void BuildList(LinkList L, int arr[], int n) {
    if (L == NULL) {
        printf("头指针为空\n");
        return;
    }

    LNode *s = L;
    for (int i = 0 ; i < n ; i++) {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        if (p == NULL) {
            printf("内存不足，节点分配失败！\n");
            return;
        }
        p->data = arr[i];
        p->next = NULL;
        s->next = p;
        s = p;
    }
    return;
}

LNode* List_FindKthFromEnd(LinkList L, int k) {
    if (k <= 0) {
        printf("k值非法\n");
        return NULL;
    }
    if (L == NULL || L->next == NULL) return NULL;
    LNode *s = L->next;
    LNode *f = L->next;
    int count = 0;
    while (1)
    {
        if (count < k) {
            f = f->next;
            count++;
            if (count < k && f == NULL) {
                printf("k值超出链表长度\n");
                return NULL;
            }
        }
        else {
            if (f == NULL) return s;
            s = s->next;
            f = f->next;
        }
    }
    
    
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