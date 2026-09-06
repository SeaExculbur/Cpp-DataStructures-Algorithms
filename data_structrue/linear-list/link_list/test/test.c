#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

int InitList(LinkList *L) {
    *L = (LNode*)malloc(sizeof(LNode));
    if (L == NULL) {
        printf("分配头节点失败\n");
        return -1;
    }
    (*L)->next = NULL;
    printf("头节点分配成功\n");
    return 0;
}

// 链表内插入节点，时间复杂度为On

int LinstInsert1(LinkList *L , int i , int value) {
    if (i < 1) {
        printf("i值非法\n");
        return -1;
    }
    LNode *p = *L;
    int j = 0;
    while (p != NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        printf("i值非法\n");
        return -1;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = value;
    s->next = p->next;
    p->next = s;
    return 0;
}

int main() {
    LinkList L;
    int res = InitList(&L);
    int res2 = LinstInsert1(&L, 1 ,5);
    LinkList ptr = L->next;
    while (ptr != NULL)
    {
        printf("%d\n" , ptr->data);
        ptr = ptr->next;
    }
    free(L);
    return 0;
}