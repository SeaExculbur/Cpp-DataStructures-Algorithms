#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int TreeMax(TreeNode *root) {
    if (root == NULL) return INT_MIN;
    int datal = TreeMax(root->left);
    int datar = TreeMax(root->right);
    int m = root->data;
    if (datal > m) m = datal;
    if (datar > m) m = datar;
    return m;
}

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

int main() {
    // 树:      5
    //        /   \
    //       3     8
    //      / \   /
    //     1   4 7

    TreeNode *root = CreateNode(5);
    root->left = CreateNode(3);
    root->right = CreateNode(8);
    root->left->left = CreateNode(1);
    root->left->right = CreateNode(4);
    root->right->left = CreateNode(7);

    printf("最大值=%d（预期 8）\n", TreeMax(root));

    // 单节点
    TreeNode *s = CreateNode(42);
    printf("单节点最大值=%d（预期 42）\n", TreeMax(s));

    // 空树
    printf("空树最大值=%d（预期 INT_MIN）\n", TreeMax(NULL));

    return 0;
}