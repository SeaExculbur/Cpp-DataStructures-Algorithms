#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

ListNode* BuildList(int arr[], int n) {
    if (n <= 0) {
        printf("n不合法\n");
        return NULL;
    }

    ListNode* L = (ListNode*)malloc(sizeof(ListNode));
    if (L==NULL) return NULL;
    L->next = NULL;
    ListNode* p = L;
    for (int i = 0 ; i < n ; i++) {
        ListNode* s = (ListNode*)malloc(sizeof(ListNode));
        if (s == NULL) return NULL;
        s->data = arr[i];
        p->next = s;
        s->next = NULL;
        p = s;
    }
    return L->next;
}

// 复用 Q3 的 ListNode 结构体和 BuildList 函数
ListNode* SwapPairs(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* newhead = head->next;
    ListNode* p1 = SwapPairs(head->next->next);

    newhead->next = head;
    head->next = p1;
    
    return newhead;
}

void PrintList(ListNode *head) {
    if (head == NULL) return;
    ListNode *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

int main() {
    // 偶数个
    int a1[] = {1, 2, 3, 4};
    ListNode *h1 = BuildList(a1, 4);
    h1 = SwapPairs(h1);
    printf("偶数个: "); PrintList(h1);
    printf("\n预期: 2 1 4 3\n");

    // 奇数个
    int a2[] = {1, 2, 3};
    ListNode *h2 = BuildList(a2, 3);
    h2 = SwapPairs(h2);
    printf("奇数个: "); PrintList(h2);
    printf("\n预期: 2 1 3\n");

    // 单节点
    int a3[] = {1};
    ListNode *h3 = BuildList(a3, 1);
    h3 = SwapPairs(h3);
    printf("单节点: "); PrintList(h3);
    printf("\n预期: 1\n");

    // 空链表
    printf("空链表: %s\n", SwapPairs(NULL) == NULL ? "NULL ✅" : "❌");
    return 0;
}