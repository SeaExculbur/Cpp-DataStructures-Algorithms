#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList MergeTwoLists(LinkList L1, LinkList L2) {
    if (L1 == NULL || L1->next == NULL) return L2;
    if (L2 == NULL || L2->next == NULL) return L1;

    LinkList L = (LNode*)malloc(sizeof(LNode));
    LNode *l1 = L1->next;
    LNode *l2 = L2->next;
    if (L == NULL) {
        printf("内存空间不足，节点分配失败\n");
        return NULL;
    }
    LNode *s = L;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data >= l2->data) {
            LNode *p = (LNode *)malloc(sizeof(LNode));
            if (p == NULL) {
                printf("p为NULL\n");
                return NULL;
            }
            p->data = l2->data;
            p->next = NULL;
            s->next = p;
            s = p;
            l2 = l2->next;
        }
        else {
            LNode *p = (LNode *)malloc(sizeof(LNode));
            if (p == NULL) {
                printf("p为NULL\n");
                return NULL;
            }
            p->data = l1->data;
            p->next = NULL;
            s->next = p;
            s = p;
            l1 = l1->next;
        }
    }
    
    while (l1 != NULL) {
    LNode *p = (LNode *)malloc(sizeof(LNode));
        if (p == NULL) {
            printf("p为NULL\n");
            return NULL;
        }
        p->data = l1->data;
        p->next = NULL;
        s->next = p;
        s = p;
        l1 = l1->next;
    }
    while (l2 != NULL) {
    LNode *p = (LNode *)malloc(sizeof(LNode));
        if (p == NULL) {
            printf("p为NULL\n");
            return NULL;
        }
        p->data = l2->data;
        p->next = NULL;
        s->next = p;
        s = p;
        l2 = l2->next;
    }
    return L;
}

int main() {
    /* ---- 手动建 L1: 1→3→5 ---- */
    LinkList L1 = (LNode *)malloc(sizeof(LNode));   // 头结点
    L1->next = NULL;
    LNode *p1 = L1;
    for (int i = 0; i < 3; i++) {
        LNode *n = (LNode *)malloc(sizeof(LNode));
        n->data = (i == 0) ? 1 : (i == 1) ? 3 : 5;
        n->next = NULL;
        p1->next = n;
        p1 = n;
    }

    /* ---- 手动建 L2: 2→4→6 ---- */
    LinkList L2 = (LNode *)malloc(sizeof(LNode));   // 头结点
    L2->next = NULL;
    LNode *p2 = L2;
    for (int i = 0; i < 3; i++) {
        LNode *n = (LNode *)malloc(sizeof(LNode));
        n->data = (i == 0) ? 2 : (i == 1) ? 4 : 6;
        n->next = NULL;
        p2->next = n;
        p2 = n;
    }

    /* ---- 测试1：两个非空链表合并 ---- */
    LinkList L3 = MergeTwoLists(L1, L2);
    printf("合并: ");
    for (LNode *p = L3->next; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n预期: 1 2 3 4 5 6\n\n");

    /* ---- 测试2：一方为空 ---- */
    LinkList empty = (LNode *)malloc(sizeof(LNode));
    empty->next = NULL;
    LinkList L4 = MergeTwoLists(L1, empty);
    printf("有一方空: ");
    for (LNode *p = L4->next; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n预期: 1 3 5\n\n");

    /* ---- 测试3：两方都空 ---- */
    // 注意：你的 MergeTwoLists 对双空返回 NULL，需要先判空再遍历
    LinkList L5 = MergeTwoLists(empty, empty);
    printf("都空: ");
    if (L5 == NULL || L5->next == NULL)
        printf("(空表)");
    printf("\n预期: (空表)\n");

    return 0;
}