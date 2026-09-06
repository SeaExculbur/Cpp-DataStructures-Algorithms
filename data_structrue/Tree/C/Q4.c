#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *CreateNode(int data) {
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

TreeNode* BSTInsert(TreeNode *root, int val) {
    if (root == NULL) return CreateNode(val);
    if (val == root->data) return root;

    if (val < root->data) root->left = BSTInsert(root->left ,val);
    else root->right = BSTInsert(root->right, val);
    return root;
}

TreeNode* BSTSearch(TreeNode *root, int val) {
    if (root == NULL) return NULL;
    if (val == root->data) return root;
    else if (val > root->data) return BSTSearch(root->right ,val);
    else return BSTSearch(root->left ,val);
}

void InOrder(TreeNode *tn) {
    if (tn == NULL) return;
    InOrder(tn->left);
    printf("%d ", tn->data);
    InOrder(tn->right);
    return;
}

int NodeCount(TreeNode *root) {
    if (root == NULL) return 0;
    return 1 + NodeCount(root->left) + NodeCount(root->right);
}

int main() {
    TreeNode *root = NULL;

    // 依次插入: 5, 3, 8, 1, 7, 9
    root = BSTInsert(root, 5);
    root = BSTInsert(root, 3);
    root = BSTInsert(root, 8);
    root = BSTInsert(root, 1);
    root = BSTInsert(root, 7);
    root = BSTInsert(root, 9);

    printf("中序遍历（应为升序）: ");
    InOrder(root);             // 复用 ex1 的中序遍历
    printf("\n预期: 1 3 5 7 8 9\n");

    // 查找
    printf("查找3: %s\n", BSTSearch(root, 3) != NULL ? "找到" : "没找到");
    printf("预期: 找到\n");
    printf("查找6: %s\n", BSTSearch(root, 6) != NULL ? "找到" : "没找到");
    printf("预期: 没找到\n");

    // 重复值不插入
    root = BSTInsert(root, 8);
    printf("重复插入8后节点数=%d（预期 6，不加）\n", NodeCount(root));

    return 0;
}