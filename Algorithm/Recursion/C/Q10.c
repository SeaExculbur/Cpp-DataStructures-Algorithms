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

int TreeHeight(TreeNode *root) {
    if (root == NULL) return 0;
    int left = 1 + TreeHeight(root->left);
    int right = 1 + TreeHeight(root->right);
    if (left >= right) return left;
    else return right;
}

bool IsBalanced(TreeNode *root) {
    if (root == NULL) return true;
    int diff = TreeHeight(root->left) - TreeHeight(root->right);
     return abs(diff) <= 1
        && IsBalanced(root->left)      // 左子树自己也要平衡
        && IsBalanced(root->right);    // 右子树自己也要平衡
}

int main() {
    // 测试1：平衡树
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    TreeNode *r1 = CreateNode(3);
    r1->left = CreateNode(9);
    r1->right = CreateNode(20);
    r1->right->left = CreateNode(15);
    r1->right->right = CreateNode(7);
    printf("平衡树: %s（预期 true）\n", IsBalanced(r1) ? "true" : "false");

    // 测试2：不平衡树
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    //      / \
    //     6   7
    TreeNode *r2 = CreateNode(1);
    r2->left = CreateNode(2);
    r2->right = CreateNode(3);
    r2->left->left = CreateNode(4);
    r2->left->right = CreateNode(5);
    r2->left->right->left = CreateNode(6);
    r2->left->right->right = CreateNode(7);
    printf("不平衡树: %s（预期 false）\n", IsBalanced(r2) ? "true" : "false");

    // 测试3：空树
    printf("空树: %s（预期 true）\n", IsBalanced(NULL) ? "true" : "false");

    // 测试4：单节点
    TreeNode *r3 = CreateNode(5);
    printf("单节点: %s（预期 true）\n", IsBalanced(r3) ? "true" : "false");

    // 测试5：根平衡，但内部节点不平衡（关键反例）
    //       1
    //      / \
    //     2   3
    //    /     \
    //   4       6
    //  /
    // 7
    // 根节点差1（平衡），但节点2左高2右高0，差2 → 整体不平衡
    TreeNode *r4 = CreateNode(1);
    r4->left = CreateNode(2);
    r4->right = CreateNode(3);
    r4->left->left = CreateNode(4);
    r4->right->right = CreateNode(6);
    r4->left->left->left = CreateNode(7);
    printf("根平衡内部不平衡: %s（预期 false）\n", IsBalanced(r4) ? "true" : "false");

    // 测试6：单侧深链（原版 if(left==NULL||right==NULL) 会漏检）
    //     1
    //    /
    //   2
    //  /
    // 3
    // 根节点左高2右高0，差2 → 不平衡
    TreeNode *r5 = CreateNode(1);
    r5->left = CreateNode(2);
    r5->left->left = CreateNode(3);
    printf("单侧深链: %s（预期 false）\n", IsBalanced(r5) ? "true" : "false");

    // 测试7：完全对称平衡树
    //       1
    //      / \
    //     2   2
    //    / \ / \
    //   3  3 3  3
    TreeNode *r6 = CreateNode(1);
    r6->left = CreateNode(2);
    r6->right = CreateNode(2);
    r6->left->left = CreateNode(3);
    r6->left->right = CreateNode(3);
    r6->right->left = CreateNode(3);
    r6->right->right = CreateNode(3);
    printf("完全对称树: %s（预期 true）\n", IsBalanced(r6) ? "true" : "false");

    // 测试8：单侧一层链（差1，是平衡的）
    //     1
    //    /
    //   2
    TreeNode *r7 = CreateNode(1);
    r7->left = CreateNode(2);
    printf("单侧一层链: %s（预期 true）\n", IsBalanced(r7) ? "true" : "false");

    return 0;
}