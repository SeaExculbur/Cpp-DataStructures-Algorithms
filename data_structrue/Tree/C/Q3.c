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

int NodeCount(TreeNode *root) {
    if (root == NULL) return 0;
    return 1 + NodeCount(root->left) + NodeCount(root->right);
}

int TreeDepth(TreeNode *root) {
    if (root == NULL) return 0;
    int leftdeepth = TreeDepth(root->left);
    int rightdeepth = TreeDepth(root->right);
    return 1 + (leftdeepth > rightdeepth ? leftdeepth : rightdeepth);
}

int main() {
    // 测试1：正常树
    TreeNode *root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);

    printf("节点数=%d（预期 4）\n", NodeCount(root));
    printf("深度=%d（预期 3）\n", TreeDepth(root));

    // 测试2：单节点
    TreeNode *single = CreateNode(7);
    printf("\n单节点树: 节点数=%d（预期 1）\n", NodeCount(single));
    printf("深度=%d（预期 1）\n", TreeDepth(single));

    // 测试3：空树
    printf("\n空树: 节点数=%d（预期 0）\n", NodeCount(NULL));
    printf("深度=%d（预期 0）\n", TreeDepth(NULL));

    return 0;
}