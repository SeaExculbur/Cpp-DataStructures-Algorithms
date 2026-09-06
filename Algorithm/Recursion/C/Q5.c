#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *CreateNode(int val) {
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    if (t == NULL) {
        printf("内存空间不足，分配失败\n");
        return NULL;
    }
    t->data = val;
    t->left = NULL;
    t->right = NULL;
    return t;
}

bool IsMirror(TreeNode *t1 , TreeNode *t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL && t2 != NULL) return false;
    if (t2 == NULL && t1 != NULL) return false;
    if (t1->data != t2->data) return false;
    return (IsMirror(t1->left , t2->right) && IsMirror(t2->left , t1->right));
}

bool IsSymmetric(TreeNode *root) {
    if (root == NULL) return true;
    return IsMirror(root->left , root->right);
}

int main() {
    // 测试1：对称树
    TreeNode *r1 = CreateNode(1);
    r1->left  = CreateNode(2); r1->right = CreateNode(2);
    r1->left->left  = CreateNode(3); r1->left->right  = CreateNode(4);
    r1->right->left = CreateNode(4); r1->right->right = CreateNode(3);
    printf("对称树: %s（预期 1/true）\n", IsSymmetric(r1) ? "true" : "false");

    // 测试2：不对称
    TreeNode *r2 = CreateNode(1);
    r2->left  = CreateNode(2); r2->right = CreateNode(2);
    r2->left->right = CreateNode(3);
    r2->right->right = CreateNode(3);
    printf("不对称树: %s（预期 0/false）\n", IsSymmetric(r2) ? "true" : "false");

    // 测试3：空树
    printf("空树: %s（预期 1/true）\n", IsSymmetric(NULL) ? "true" : "false");

    // 测试4：单节点
    TreeNode *r3 = CreateNode(5);
    printf("单节点: %s（预期 1/true）\n", IsSymmetric(r3) ? "true" : "false");

    return 0;
}