#include <iostream>
using namespace std;

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr) ,right(nullptr) {}
} TreeNode;

int NodeCount(TreeNode *root) {
    if (root == nullptr) return 0;
    return 1 + NodeCount(root->right) + NodeCount(root->left);
}

int TreeDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    int leftdepth = TreeDepth(root->left);
    int rightdepth = TreeDepth(root->right);
    return 1 + (rightdepth > leftdepth ? rightdepth : leftdepth);
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    cout << "节点数=" << NodeCount(root) << "（预期 4）" << endl;
    cout << "深度=" << TreeDepth(root) << "（预期 3）" << endl;

    TreeNode *single = new TreeNode(7);
    cout << "\n单节点: 节点数=" << NodeCount(single) << "（预期 1）" << endl;
    cout << "深度=" << TreeDepth(single) << "（预期 1）" << endl;

    cout << "\n空树: 节点数=" << NodeCount(nullptr) << "（预期 0）" << endl;
    cout << "深度=" << TreeDepth(nullptr) << "（预期 0）" << endl;

    return 0;
}