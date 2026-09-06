#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    //  ↑ 构造函数：C++ 里可以省掉手动写 CreateNode
};

void PreOrder(TreeNode *root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(TreeNode *root) {
    if (root == nullptr) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(TreeNode *root) {
    if (root == nullptr) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "先序: "; PreOrder(root); cout << "\n预期: 1 2 4 5 3" << endl;
    cout << "中序: "; InOrder(root); cout << "\n预期: 4 2 5 1 3" << endl;
    cout << "后序: "; PostOrder(root); cout << "\n预期: 4 5 2 3 1" << endl;

    return 0;
}