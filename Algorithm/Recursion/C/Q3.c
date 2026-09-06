#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

ListNode* ReverseList(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *p = ReverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}

ListNode* BuildList(int arr[], int n) {
    if (n <= 0) return NULL;
    ListNode *L = (ListNode*)malloc(sizeof(ListNode));
    if (L == NULL) return NULL;
    ListNode *p = L;
    L->next = NULL;
    for (int i = 0; i < n ; i ++) {
        ListNode *s = (ListNode *)malloc(sizeof(ListNode));
        s->data = arr[i];
        p->next = s;
        s->next = NULL;
        p = s;
    }
    return L->next;
    
}

// 建表函数: ListNode* BuildList(int arr[], int n) { ... }

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode *head = BuildList(arr1, 5);
    for (ListNode *p = head; p; p = p->next) printf("%d ", p->data);
    head = ReverseList(head);
    printf("反转后: ");
    for (ListNode *p = head; p; p = p->next) printf("%d ", p->data);
    printf("\n预期: 5 4 3 2 1\n");

    // 单节点
    ListNode *single = BuildList((int[]){7}, 1);
    single = ReverseList(single);
    printf("单节点: %d（预期 7）\n", single->data);

    // 空链表
    printf("空链表: %s\n", ReverseList(NULL) == NULL ? "NULL ✅" : "❌");

    return 0;
}