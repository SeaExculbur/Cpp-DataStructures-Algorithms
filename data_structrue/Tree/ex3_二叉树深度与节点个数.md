# 练习3：二叉树的深度与节点个数

## 题目

实现两个递归函数：
1. `int NodeCount(TreeNode *root)` — 返回二叉树节点总数
2. `int TreeDepth(TreeNode *root)` — 返回二叉树深度（根节点深度为 1）

## 递归思路

```
节点总数 = 1（自己）+ 左子树节点数 + 右子树节点数
深度 = 1（自己这层）+ max(左子树深度, 右子树深度)
```

```
        1             ← 深度=1
       / \
      2   3           ← 深度=2
     /
    4                 ← 深度=3

NodeCount: 1 + 2 + 1 = 4
TreeDepth: 1 + max(2, 1) = 3
```

```c
int NodeCount(TreeNode *root) {
    if (root == NULL) return 0;     // 空树 0 个节点
    return 1 + NodeCount(root->left) + NodeCount(root->right);
}

int TreeDepth(TreeNode *root) {
    if (root == NULL) return 0;     // 空树深度为 0
    int leftDepth = TreeDepth(root->left);
    int rightDepth = TreeDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}
```

## 测试用例（C）

```c
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
```

---

## C++ 版本

语法和 C 版本完全一致，仅输出用 `cout`。

### 测试用例（C++）

```cpp
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
```
