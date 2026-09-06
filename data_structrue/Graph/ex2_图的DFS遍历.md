# 练习2：图的 DFS 遍历

## 题目

实现图的**深度优先遍历**（DFS）。从顶点 `start` 出发，按 DFS 顺序打印访问到的顶点。

## 和树的先序遍历的关系

树的先序 = 图的 DFS 特例。唯一的区别：图**可能有环**，需要 `visited` 数组防止重复访问。

```
树（无环）:            图（有环）:
    1                      0 —— 1
   / \                     |    |
  2   3                    2 —— 3

树: 递归下去不会走回父节点      图: 从 0→1→3→2→0 会绕回去！
  不需要 visited                必须有 visited 防止死循环
```

## 思路

```c
void DFS(int v, int visited[], int adj[][MAXV], int n) {
    visited[v] = 1;                      // ① 标记当前顶点已访问
    printf("%d ", v);                    // ② 访问当前顶点

    for (int i = 0; i < n; i++) {        // ③ 遍历所有可能的邻居
        if (adj[v][i] == 1               // 有边
            && visited[i] == 0) {        // 且没被访问过
            DFS(i, visited, adj, n);     // 递归访问
        }
    }
}
```

这和你树的 `PreOrder` 结构完全一样，只是多了一层 `visited` 检查 + 一个循环找邻居。

## 测试用例（C）

```c
#include <stdio.h>
#include <string.h>  // memset

#define MAXV 10

int main() {
    int adj[MAXV][MAXV] = {0};
    int n = 5;
    int visited[MAXV];

    // 建图:
    //   0 —— 1 —— 4
    //   |    |
    //   2 —— 3
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][4] = adj[4][1] = 1;
    adj[2][3] = adj[3][2] = 1;

    // DFS 从 0 开始
    memset(visited, 0, sizeof(visited));
    printf("DFS 从 0 开始: ");
    DFS(0, visited, adj, n);
    printf("\n预期: 0 1 3 2 4（或 0 2 3 1 4，和遍历顺序有关）\n");

    return 0;
}
```

**注意**：DFS 结果不唯一——邻接矩阵里先扫到哪个邻居就先走那边，只要不重复、不遗漏都对。

## 需要实现的函数

- `void DFS(int v, int visited[], int adj[][MAXV], int n)`

---

## C++ 版本

用 `vector<vector<int>> &adj` 替代 `int adj[][MAXV]`，`vector<int> &visited` 替代 `int visited[]`。递归逻辑完全相同。
