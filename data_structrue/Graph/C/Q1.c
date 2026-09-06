#include <stdio.h>

#define MAXV 10          // 最大顶点数
int adj[MAXV][MAXV];     // 邻接矩阵，默认全 0
int n;                   // 实际顶点数

void InitGraph(int data) {
    if (MAXV <= data || data < 0) return;
    n = data;
}

void AddEdge(int x, int y) {
    if (x >= n || y >= n || x < 0 || y < 0) {
        printf("x或y非法\n");
        return;
    }
    adj[x][y] = adj[y][x] = 1;
}

void PrintGraph() {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    return;
}


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