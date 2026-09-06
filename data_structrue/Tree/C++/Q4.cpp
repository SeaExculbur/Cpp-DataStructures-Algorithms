#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int val) : data(val) , left(nullptr) , right(nullptr) {}
};

TreeNode *BSTInsert(TreeNode *root , int val) {
    if (root == nullptr) return new TreeNode(val);
    if (root->data == val) return root;
    else if (root->data < val) root->right = BSTInsert(root->right ,val);
    else root->left = BSTInsert(root->left ,val);
    return root;
}

TreeNode* BSTSearch(TreeNode *root, int val) {
    if (root == nullptr) return root;
    if (root->data == val) return root;
    else if (root->data > val) return BSTSearch(root->left ,val);
    else return BSTSearch(root->right ,val);
}

void InOrder(TreeNode *root) {
    if (root == nullptr) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int NodeCount(TreeNode *root) {
    if (root == nullptr) return 0;
    return 1 + NodeCount(root->left) + NodeCount(root->right);
}

int main() {
    TreeNode *root = nullptr;
    
    root = BSTInsert(root, 5);
    root = BSTInsert(root, 3);
    root = BSTInsert(root, 8);
    root = BSTInsert(root, 1);
    root = BSTInsert(root, 7);
    root = BSTInsert(root, 9);

    cout << "中序（应为升序）: "; InOrder(root);
    cout << "\n预期: 1 3 5 7 8 9" << endl;

    cout << "查找3: " << (BSTSearch(root, 3) ? "找到" : "没找到") << "（预期: 找到）" << endl;
    cout << "查找6: " << (BSTSearch(root, 6) ? "找到" : "没找到") << "（预期: 没找到）" << endl;
    cout << "重复插入8后节点数=" << NodeCount(root) << "（预期 6）" << endl;

    return 0;
}