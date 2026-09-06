/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
    L->next = NULL;
    struct ListNode* ptr = L;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int res = x + y + carry;
        carry = res / 10;
        int digit = res % 10;

        struct ListNode* node =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = digit;
        node->next = NULL;
        ptr->next = node;
        ptr = node;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    struct ListNode* result = L->next;
    free(L);
    return result;
}