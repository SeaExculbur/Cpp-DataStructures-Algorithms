                               # 练习1：图的存储

## 背景

图 = 顶点集合 + 边集合。两种主流存储方式：

### 邻接矩阵

用二维数组，`adj[i][j] == 1` 表示 i→j 有边。

```c
#define MAXV 10          // 最大顶点数
int adj[MAXV][MAXV];     // 邻接矩阵，默认全 0
int n;                   // 实际顶点数
```

```
图:  0 —— 1     邻接矩阵:
     |    |      adj[0][1]=1  adj[1][0]=1
     2 —— 3      adj[0][2]=1  adj[2][0]=1
                 adj[1][3]=1  adj[3][1]=1
                 adj[2][3]=1  adj[3][2]=1
```

优点：O(1) 判断两顶点是否有边。缺点：O(n²) 空间，稀疏图浪费。

### 邻接表

每个顶点维护一个链表，存它指向的邻居。

```c
// 边节点
typedef struct EdgeNode {
    int adjvex;             // 邻居编号
    struct EdgeNode *next;
} EdgeNode;

// 顶点
typedef struct {
    int data;
    EdgeNode *firstEdge;    // 指向第一条边
} VertexNode;

VertexNode adjList[MAXV];   // 邻接表
```

优点：空间 O(n+e)，稀疏图省内存。

## 要求（只做邻接矩阵）

1. 定义 `int adj[MAXV][MAXV]` 和 `int n`
2. 写 `void InitGraph(int vertexCount)` — 初始化 n 个顶点的空图（全 0）
3. 写 `void AddEdge(int u, int v)` — 添加无向边 `u↔v`（同时设 `adj[u][v]=1` 和 `adj[v][u]=1`）
4. 写 `void PrintGraph()` — 打印邻接矩阵

## 测试用例（C）

```c
int main() {
    // 建图: 0-1, 0-2, 1-3, 2-3
    //   0 —— 1
    //   |    |
    //   2 —— 3
    InitGraph(4);          // 4 个顶点: 0,1,2,3
    AddEdge(0, 1);
    AddEdge(0, 2);
    AddEdge(1, 3);
    AddEdge(2, 3);

    PrintGraph();
    // 预期输出:
    //   0 1 1 0
    //   1 0 0 1
    //   1 0 0 1
    //   0 1 1 0

    return 0;
}
```

---

## C++ 版本

邻接矩阵用 `vector<vector<int>>` 替代二维数组：

```cpp
vector<vector<int>> adj;      // 等价 int adj[MAXV][MAXV]

// 初始化 n 个顶点:
adj.resize(n, vector<int>(n, 0));
```

其余逻辑和 C 一致。测试用例同上，输出用 `cout`。
