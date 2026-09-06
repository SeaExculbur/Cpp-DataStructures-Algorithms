# 练习1：二叉树的建立与递归遍历

## 结构体定义

```c
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
```

和链表节点的区别：只有一个 `next`→两个 `left`、`right`。

## 三种递归遍历

```
       1
      / \
     2   3
    / \   \
   4   5   6

先序（根→左→右）：1  2  4  5  3  6
中序（左→根→右）：4  2  5  1  3  6
后序（左→右→根）：4  5  2  6  3  1
```

递归三行代码，只换顺序：

```c
void PreOrder(TreeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->data);   // 根
    PreOrder(root->left);        // 左
    PreOrder(root->right);       // 右
}

void InOrder(TreeNode *root) {
    if (root == NULL) return;
    InOrder(root->left);         // 左
    printf("%d ", root->data);   // 根
    InOrder(root->right);        // 右
}

void PostOrder(TreeNode *root) {
    if (root == NULL) return;
    PostOrder(root->left);       // 左
    PostOrder(root->right);      // 右
    printf("%d ", root->data);   // 根
}
```

## 要求

1. 手写创建函数 `TreeNode* CreateNode(int data)` — 新建节点，`left` 和 `right` 初始为 `NULL`
2. 实现上述三个递归遍历
3. `main` 中手动构造下面这棵树并测试三种遍历

```
构造目标树:
        1
       / \
      2   3
     / \
    4   5
```

## 测试用例（C）

```c
// 手动构造树的辅助函数
TreeNode* CreateNode(int data) { ... }

int main() {
    // 手动建树
    TreeNode *root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);

    printf("先序: "); PreOrder(root);
    printf("\n预期: 1 2 4 5 3\n");

    printf("中序: "); InOrder(root);
    printf("\n预期: 4 2 5 1 3\n");

    printf("后序: "); PostOrder(root);
    printf("\n预期: 4 5 2 3 1\n");

    return 0;
}
```

---

## C++ 版本

### 要求

用 `struct TreeNode` + 手动构造，和 C 版本语法完全一致。唯一区别：输出用 `cout`。

### 测试用例（C++）

```cpp
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    //  ↑ 构造函数：C++ 里可以省掉手动写 CreateNode
};

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
```

**注意**：C++ 用 `new` 替代 C 的 `malloc`，用 `nullptr` 替代 `NULL`。构造函数那行如果看不懂，先照抄——不影响递归遍历的核心逻辑。
