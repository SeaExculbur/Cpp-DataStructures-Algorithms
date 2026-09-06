#include <iostream>
#include <queue>

using namespace std;

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
} TreeNode;

void LevelOrder(TreeNode *root) {
    if (root == nullptr) return;
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty())
    {
        root = Q.front();
        cout << root->data << " ";
        Q.pop();
        if (root->left != nullptr) Q.push(root->left);
        if (root->right != nullptr) Q.push (root->right);
    }
    return;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "层序: "; LevelOrder(root);
    cout << "\n预期: 1 2 3 4 5 6" << endl;

    cout << "空树层序: "; LevelOrder(nullptr);
    cout << "\n预期: (无输出)" << endl;

    return 0;
}