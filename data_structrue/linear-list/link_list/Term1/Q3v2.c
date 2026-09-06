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

void List_Reverse(LinkList *L) {
    if (*L == NULL) return;
    LNode *p = (*L)->next;
    // 申请新的头节点，创建新的单链表
    LNode *k = (LNode *)malloc(sizeof(LNode));
    if (k == NULL) return;
    k->next = NULL;
    // 使用头插法建立单链表，造成反转
    while (p != NULL)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        if (s == NULL) {
            printf("内存不足，无法分配\n");
            return;
        }
        s->data = p->data;
        s->next = k->next;
        k->next = s;
        LNode *tmp = p;
        p = p->next;
        free(tmp);
    }
    // 让头指针指向新单链表头节点
    *L = k; 
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
    List_Reverse(&L);
    printf("--------------------\n");
    PrintList(L);
    return 0;
}