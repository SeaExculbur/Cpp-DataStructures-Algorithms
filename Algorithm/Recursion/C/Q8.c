#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* CreateNode(int n) {
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    if (t == NULL) return NULL;
    t->data = n;
    t->left = NULL;
    t->right = NULL;
    return t;
}

TreeNode* InvertTree(TreeNode *root) {
    if (root == NULL) return NULL;
    TreeNode *left = InvertTree(root->left);
    TreeNode *right = InvertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

void PreOrder(TreeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
    return;
}

int main() {
    // 建树:       4
    //           /   \
    //          2     7
    //         / \   / \
    //        1   3 6   9
    TreeNode *root = CreateNode(4);
    root->left = CreateNode(2);
    root->right = CreateNode(7);
    root->left->left = CreateNode(1);
    root->left->right = CreateNode(3);
    root->right->left = CreateNode(6);
    root->right->right = CreateNode(9);

    printf("翻转前先序: "); PreOrder(root);
    printf("\n预期: 4 2 1 3 7 6 9\n");

    root = InvertTree(root);
    printf("翻转后先序: "); PreOrder(root);
    printf("\n预期: 4 7 9 6 2 3 1\n");

    // 空树
    printf("空树: %s\n", InvertTree(NULL) == NULL ? "NULL ✅" : "❌");

    // 单节点
    TreeNode *s = CreateNode(42);
    s = InvertTree(s);
    printf("单节点值=%d（预期 42）\n", s->data);
    return 0;
}