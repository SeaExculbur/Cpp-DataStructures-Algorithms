#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *CreateNode(int x) {
    TreeNode *tn = (TreeNode *)malloc(sizeof(TreeNode));
    if (tn == NULL) {
        printf("内存不足，分配失败\n");
        return NULL;
    }
    tn->data = x;
    tn->left = NULL;
    tn->right = NULL;
    return tn;
}

int TreeDepth(TreeNode *root) {
    if (root == NULL) return 0;
    int leftdep = TreeDepth(root->left);
    int rightdep = TreeDepth(root->right);
    return 1 + (leftdep > rightdep ? leftdep : rightdep);
}

bool IsBalanced(TreeNode *root) {
    if (root == NULL) return true;
    int n = TreeDepth(root->left) - TreeDepth(root->right);
    if (n > 1 || n < -1) return false;
    return IsBalanced(root->left) && IsBalanced(root->right);
}

int main() {
    // 平衡树
    TreeNode *r1 = CreateNode(3);
    r1->left  = CreateNode(9);
    r1->right = CreateNode(20);
    r1->right->left  = CreateNode(15);
    r1->right->right = CreateNode(7);
    printf("平衡树: %s（预期 1）\n", IsBalanced(r1) ? "true" : "false");

    // 不平衡（左斜）
    TreeNode *r2 = CreateNode(1);
    r2->left = CreateNode(2);
    r2->left->left = CreateNode(3);
    r2->left->left->left = CreateNode(4);
    printf("左斜树: %s（预期 0）\n", IsBalanced(r2) ? "true" : "false");

    // 空树
    printf("空树:   %s（预期 1）\n", IsBalanced(NULL) ? "true" : "false");

    // 单节点
    TreeNode *r3 = CreateNode(5);
    printf("单节点: %s（预期 1）\n", IsBalanced(r3) ? "true" : "false");

    return 0;
}