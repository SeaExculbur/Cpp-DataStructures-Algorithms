# 练习3：图的 BFS 遍历

## 题目

实现图的**广度优先遍历**（BFS）。从顶点 `start` 出发，按 BFS 顺序打印访问到的顶点。

## 和树的层序遍历的关系

树的层序 = 图的 BFS 特例。公式完全一样：

```
根入队 → 循环(出队→打印→所有未访问邻居入队)
```

唯一增加：`visited` 数组。

## 思路

```c
void BFS(int start, int visited[], int adj[][MAXV], int n) {
    int queue[MAXV];
    int front = 0, rear = 0;

    queue[rear++] = start;              // ① 起点入队
    visited[start] = 1;                 // ② 标记已访问

    while (front < rear) {              // ③ 队列不空
        int v = queue[front++];         // 出队
        printf("%d ", v);               // 访问

        for (int i = 0; i < n; i++) {   // ④ 所有未访问邻居入队
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;         // 入队时就标记！不是出队时
            }
        }
    }
}
```

**关键细节**：`visited` 必须在入队时标记，不是出队时。否则同一个邻居被多个顶点同时看到时，会重复入队。

## 测试用例（C）

```c
#include <stdio.h>
#include <string.h>

#define MAXV 10

int main() {
    int adj[MAXV][MAXV] = {0};
    int n = 5;
    int visited[MAXV];

    // 同一张图
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][4] = adj[4][1] = 1;
    adj[2][3] = adj[3][2] = 1;

    memset(visited, 0, sizeof(visited));
    printf("BFS 从 0 开始: ");
    BFS(0, visited, adj, n);
    printf("\n预期: 0 1 2 3 4（逐层展开，顺序不唯一）\n");

    return 0;
}
```

## 需要实现的函数

- `void BFS(int start, int visited[], int adj[][MAXV], int n)`

---

## C++ 版本

用 `vector<vector<int>> &adj` 替代 `int adj[][MAXV]`，用 `queue<int>` 替代手写队列（正好复习 STL 队列）。递归逻辑换为循环。`visited` 用 `vector<int>`。
