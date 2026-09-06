#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode * next;
} LNode , *LinkList;

void InitList(LinkList *L) {
    (*L) = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL) {
        return;
    }
    (*L)->next = NULL;
    return;
}

void Increaselist(LinkList L) {
    if (L == NULL) {
        return;
    }
    LNode *s = L;
    int num;
    printf("请输入要插入的节点数据，输入9999循环停止\n");
    scanf("%d" , &num);
    while (num != 9999) {
    LNode *p = (LNode *)malloc(sizeof(LNode));
    if (p == NULL) {
        printf("内存不足，节点分配失败\n");
        return;
    }
    p->data = num;
    s->next = p;
    p->next = NULL;
    s = p;
    scanf("%d" , &num);
    }
    return;
}

int main() {
    LinkList L;
    InitList(&L);
    Increaselist(L);
    LNode *p = L;
    while (p != NULL)
    {
        printf("%d\n" , (p->next)->data);
        p = p->next;
    }
    return 0;
}