#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode , *LinkList;

int List_TailInsert(LinkList *L) {
    int x;
    *L = (LinkList)malloc(sizeof(LNode));      // 建立头节点
    if (L == NULL) {
        return -1;
    }
    (*L)->next = NULL;
    LNode *s , *r = *L;           // 双指针建立链表，时间复杂度为On
    printf("请输入数据，输入9999停止\n");
    scanf("%d",&x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return 0;
}

int main() {
    LinkList L;
    List_TailInsert(&L);
    LinkList ptr = L->next;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    return 0;
    
}