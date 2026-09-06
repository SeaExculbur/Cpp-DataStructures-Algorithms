# 练习4：二叉搜索树（BST）的插入和查找

## 题目

**BST 规则**：对于任意节点，左子树所有值 < 根节点值 < 右子树所有值。

```
        5
       / \
      3   8
     /   / \
    1   7   9
```

## 需要实现的函数

### 1. 插入 `TreeNode* BSTInsert(TreeNode *root, int val)`

在 BST 中插入新值，保持 BST 性质。返回新的根节点（首次插入时根为 NULL，返回新节点）。

```c
// 递归思路
if (root == NULL)     → 到这里就插入，创建新节点返回
if (val < root->data) → 往左子树插
if (val > root->data) → 往右子树插
// val 已存在则不做任何事（BST 不存重复值）
```

### 2. 查找 `TreeNode* BSTSearch(TreeNode *root, int val)`

在 BST 中查找指定值，找到返回节点指针，找不到返回 NULL。

```c
if (root == NULL || root->data == val) → 返回 root
if (val < root->data) → 去左子树找
else                  → 去右子树找
```

**和二分查找一样**——每次砍掉一半子树，O(log n)。

## 测试用例（C）

```c
int main() {
    TreeNode *root = NULL;

    // 依次插入: 5, 3, 8, 1, 7, 9
    root = BSTInsert(root, 5);
    root = BSTInsert(root, 3);
    root = BSTInsert(root, 8);
    root = BSTInsert(root, 1);
    root = BSTInsert(root, 7);
    root = BSTInsert(root, 9);

    printf("中序遍历（应为升序）: ");
    InOrder(root);             // 复用 ex1 的中序遍历
    printf("\n预期: 1 3 5 7 8 9\n");

    // 查找
    printf("查找3: %s\n", BSTSearch(root, 3) != NULL ? "找到" : "没找到");
    printf("预期: 找到\n");
    printf("查找6: %s\n", BSTSearch(root, 6) != NULL ? "找到" : "没找到");
    printf("预期: 没找到\n");

    // 重复值不插入
    root = BSTInsert(root, 8);
    printf("重复插入8后节点数=%d（预期 6，不加）\n", NodeCount(root));

    return 0;
}
```

---

## C++ 版本

### 要求

语法和 C 一致，`NULL` 换成 `nullptr`，`printf` 换成 `cout`。递归逻辑完全相同。

### 测试用例（C++）

```cpp
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
```
