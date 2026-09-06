#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* CreateNode(int n) {
    TreeNode* t = (TreeNode*)malloc(sizeof(TreeNode));
    if (t == NULL) return NULL;
    t->data = n;
    t->left = NULL;
    t->right = NULL;
    return t;
}

bool IsSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->data != q->data) return false;
    return (IsSameTree(p->left, q->left) && IsSameTree(p->right, q->right));
}

int main() {
    // 测试1：相同
    TreeNode *p1 = CreateNode(1);
    p1->left = CreateNode(2); p1->right = CreateNode(3);
    TreeNode *q1 = CreateNode(1);
    q1->left = CreateNode(2); q1->right = CreateNode(3);
    printf("相同树: %s（预期 true）\n", IsSameTree(p1, q1) ? "true" : "false");

    // 测试2：结构不同
    TreeNode *p2 = CreateNode(1);
    p2->left = CreateNode(2);
    TreeNode *q2 = CreateNode(1);
    q2->right = CreateNode(2);
    printf("结构不同: %s（预期 false）\n", IsSameTree(p2, q2) ? "true" : "false");

    // 测试3：都为空
    printf("都为空: %s（预期 true）\n", IsSameTree(NULL, NULL) ? "true" : "false");

    // 测试4：一个空一个不空
    TreeNode *t = CreateNode(1);
    printf("一空一不空: %s（预期 false）\n", IsSameTree(t, NULL) ? "true" : "false");
    return 0;
}