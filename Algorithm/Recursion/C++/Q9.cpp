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

// ========== 你要实现的函数 ==========
bool IsSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;
    if (p->data != q->data) return false;
    return (IsSameTree(p->left, q->left) && IsSameTree(p->right, q->right));
}

// ========== 测试 ==========
int main() {
    // 测试1：相同
    TreeNode *p1 = CreateNode(1);
    p1->left = CreateNode(2); p1->right = CreateNode(3);
    TreeNode *q1 = CreateNode(1);
    q1->left = CreateNode(2); q1->right = CreateNode(3);
    cout << "相同树: " << (IsSameTree(p1, q1) ? "true" : "false")
         << " (预期 true)" << endl;

    // 测试2：结构不同
    TreeNode *p2 = CreateNode(1);
    p2->left = CreateNode(2);
    TreeNode *q2 = CreateNode(1);
    q2->right = CreateNode(2);
    cout << "结构不同: " << (IsSameTree(p2, q2) ? "true" : "false")
         << " (预期 false)" << endl;

    // 测试3：都为空
    cout << "都为空: " << (IsSameTree(nullptr, nullptr) ? "true" : "false")
         << " (预期 true)" << endl;

    // 测试4：一个空一个不空
    TreeNode *t = CreateNode(1);
    cout << "一空一不空: " << (IsSameTree(t, nullptr) ? "true" : "false")
         << " (预期 false)" << endl;

    return 0;
}