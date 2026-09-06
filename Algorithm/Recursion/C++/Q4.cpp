#include <iostream>
#include <climits>
using namespace std;

// ========== 结构体定义 ==========
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ========== 创建节点 ==========
TreeNode* CreateNode(int val) {
    return new TreeNode(val);
}

// ========== 你要实现的函数 ==========
int TreeMax(TreeNode *root) {
    if (root == nullptr) return INT_MIN;
    int datal = TreeMax(root->left);
    int datar = TreeMax(root->right);
    int m = root->data;
    if (m < datal) m = datal;
    if (m < datar) m = datar;
    return m;
}

// ========== 测试 ==========
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

    cout << "最大值=" << TreeMax(root) << " (预期 8)" << endl;

    // 单节点
    TreeNode *s = CreateNode(42);
    cout << "单节点最大值=" << TreeMax(s) << " (预期 42)" << endl;

    // 空树
    cout << "空树最大值=" << TreeMax(nullptr) << " (预期 INT_MIN = " << INT_MIN << ")" << endl;

    return 0;
}