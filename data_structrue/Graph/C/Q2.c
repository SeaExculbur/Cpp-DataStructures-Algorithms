#include <stdio.h>
#include <string.h>  // memset

#define MAXV 10

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