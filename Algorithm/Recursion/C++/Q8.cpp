#include <iostream>
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

// ========== 先序遍历（用于验证）==========
void PreOrder(TreeNode *root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// ========== 你要实现的函数 ==========
TreeNode* InvertTree(TreeNode *root) {
    if (root == nullptr) return nullptr;
    TreeNode *left = InvertTree(root->left);
    TreeNode *right = InvertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

// ========== 测试 ==========
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

    cout << "翻转前先序: "; PreOrder(root);
    cout << "\n预期: 4 2 1 3 7 6 9" << endl;

    root = InvertTree(root);

    cout << "翻转后先序: "; PreOrder(root);
    cout << "\n预期: 4 7 9 6 2 3 1" << endl;

    // 空树
    cout << "空树: "
         << (InvertTree(nullptr) == nullptr ? "nullptr ✅" : "❌") << endl;

    // 单节点
    TreeNode *s = CreateNode(42);
    s = InvertTree(s);
    cout << "单节点值=" << s->data << " (预期 42)" << endl;

    return 0;
}