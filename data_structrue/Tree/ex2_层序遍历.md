# 练习2：层序遍历（BFS）

## 题目

实现二叉树的**层序遍历**——逐层从上到下、每层从左到右打印节点。

```
        1
       / \
      2   3
     / \   \
    4   5   6

层序: 1  2  3  4  5  6
```

## 思路

层序 = BFS = 用**队列**。你刚写完队列，正好拿来用：

```
1. 根节点入队
2. 队列不空就循环:
    出队 → 打印 → 左孩子入队 → 右孩子入队
```

```
初始: 队列=[1]
出1: 打印1, 入2, 入3 → 队列=[2,3]
出2: 打印2, 入4, 入5 → 队列=[3,4,5]
出3: 打印3, 入6      → 队列=[4,5,6]
出4: 打印4, 无孩子   → 队列=[5,6]
出5: 打印5, 无孩子   → 队列=[6]
出6: 打印6, 无孩子   → 队列=[]
结束
```

## 队列复用

可以直接调用你 `Sequential_Queue` 里写好的队列代码，或者在这个文件里写一个简化版队列（只保留 `TreeNode*` 类型的 `EnQueue`/`DeQueue`/`IsEmpty`）。

## 函数签名

```c
void LevelOrder(TreeNode *root);
```

## 测试用例（C）

```c
// 同一棵树
int main() {
    TreeNode *root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);
    root->right->right = CreateNode(6);

    printf("层序: "); LevelOrder(root);
    printf("\n预期: 1 2 3 4 5 6\n");

    // 空树
    printf("空树层序: "); LevelOrder(NULL);
    printf("\n预期: (无输出)\n");

    return 0;
}
```

---

## C++ 版本

### 要求

用 `queue<TreeNode*>` 实现 `void LevelOrder(TreeNode *root)`。

**注意**：队列里存的是节点**指针**，不是节点本身。操作和 `queue<int>` 一样，类型换成 `TreeNode*`。

### 测试用例（C++）

```cpp
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
```
