# 练习4：图的连通分量

## 题目

实现 `int ConnectedComponents(int adj[][MAXV], int n)`，返回无向图的**连通分量个数**。一个连通分量就是图中的一个"独立岛屿"——岛内可达，岛间无边。

```
图1（1个连通分量）:       图2（2个连通分量）:
   0 —— 1                  0 —— 1       2 —— 3 —— 4
   |    |                  ↓ 一个岛 ↓   ↓ 另一个岛 ↓
   2 —— 3

result = 1                result = 2
```

## 思路

每次 DFS 会从一个起点探索完整个可达区域。调用一次 DFS 标记完一个连通分量。遍历所有顶点，每遇到一个未访问的顶点就计数+1、DFS 一次：

```c
int ConnectedComponents(int adj[][MAXV], int n) {
    int visited[MAXV] = {0};
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {       // 发现一个未访问的顶点
            count++;                 // 新分量！
            DFS(i, visited, adj, n); // 把这个分量全部标记
        }
    }
    return count;
}
```

`visited` 是全图共享的——一次 DFS 遍历完一个岛，循环继续找下一个未访问的顶点。

## 测试用例（C）

```c
int main() {
    int adj[MAXV][MAXV] = {0};
    int n;

    // 测试1：连通图（1个分量）
    //   0-1, 0-2, 1-3, 2-3
    n = 4;
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    printf("连通图: 分量数=%d（预期 1）\n", ConnectedComponents(adj, n));

    // 测试2：两个独立连通分量
    //   分量1: 0-1    分量2: 2-3-4
    memset(adj, 0, sizeof(adj));
    n = 5;
    adj[0][1] = adj[1][0] = 1;          // 分量1: 0↔1
    adj[2][3] = adj[3][2] = 1;          // 分量2: 2↔3
    adj[3][4] = adj[4][3] = 1;          // 分量2: 3↔4
    printf("两个分量: 分量数=%d（预期 2）\n", ConnectedComponents(adj, n));

    // 测试3：全孤立顶点
    memset(adj, 0, sizeof(adj));
    n = 4;
    printf("4个孤立顶点: 分量数=%d（预期 4）\n", ConnectedComponents(adj, n));

    return 0;
}
```

---

## C++ 版本

用 `vector<vector<int>> &adj` 替代 `int adj[][MAXV]`，`vector<int> &visited`。逻辑完全相同。
