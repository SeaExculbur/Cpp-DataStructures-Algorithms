#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* CreateNode(int data) {
    TreeNode *tn = (TreeNode *)malloc(sizeof(TreeNode));
    if (tn == NULL) {
        printf("内存不足，节点分配失败\n");
        return NULL;
    }
    tn->data = data;
    tn->left = NULL;
    tn->right = NULL;
    return tn;
}

void PreOrder(TreeNode *tn) {
    if (tn == NULL) return;
    printf("%d " , tn->data);
    PreOrder(tn->left);
    PreOrder(tn->right);
    return;
}

void InOrder(TreeNode *tn) {
    if (tn == NULL) return;
    InOrder(tn->left);
    printf("%d ", tn->data);
    InOrder(tn->right);
    return;
}

void PostOrder(TreeNode *tn) {
    if (tn == NULL) return;
    PostOrder(tn->left);
    PostOrder(tn->right);
    printf("%d ", tn->data);
    return;
}

int main() {
    // 手动建树
    TreeNode *root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);

    printf("先序: "); PreOrder(root);
    printf("\n预期: 1 2 4 5 3\n");

    printf("中序: "); InOrder(root);
    printf("\n预期: 4 2 5 1 3\n");

    printf("后序: "); PostOrder(root);
    printf("\n预期: 4 5 2 3 1\n");

    return 0;
}