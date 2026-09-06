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

bool IsMirror(TreeNode *t1 , TreeNode *t2) {
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr && t2 != nullptr) return false;
    if (t2 == nullptr && t1 != nullptr) return false;
    if (t1->data != t2->data) return false;
    return (IsMirror(t1->left , t2->right) && IsMirror(t1->right , t2->left));
}

// ========== 你要实现的函数 ==========
// 提示：需要辅助函数 IsMirror(TreeNode *t1, TreeNode *t2)
bool IsSymmetric(TreeNode *root) {
    if (root == nullptr) return true;
    return IsMirror(root->left , root->right);
}

// ========== 测试 ==========
int main() {
    // 测试1：对称树
    TreeNode *r1 = CreateNode(1);
    r1->left  = CreateNode(2); r1->right = CreateNode(2);
    r1->left->left  = CreateNode(3); r1->left->right  = CreateNode(4);
    r1->right->left = CreateNode(4); r1->right->right = CreateNode(3);
    cout << "对称树: " << (IsSymmetric(r1) ? "true" : "false") << " (预期 true)" << endl;

    // 测试2：不对称
    TreeNode *r2 = CreateNode(1);
    r2->left  = CreateNode(2); r2->right = CreateNode(2);
    r2->left->right = CreateNode(3);
    r2->right->right = CreateNode(3);
    cout << "不对称树: " << (IsSymmetric(r2) ? "true" : "false") << " (预期 false)" << endl;

    // 测试3：空树
    cout << "空树: " << (IsSymmetric(nullptr) ? "true" : "false") << " (预期 true)" << endl;

    // 测试4：单节点
    TreeNode *r3 = CreateNode(5);
    cout << "单节点: " << (IsSymmetric(r3) ? "true" : "false") << " (预期 true)" << endl;

    return 0;
}