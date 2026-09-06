#include <stdio.h>
#include <string.h>

#define MAXV 10
#define MaxSize 10      // 实际最多存 MaxSize-1 = 9 个元素

typedef struct {
    int data[MaxSize];
    int front;         // 队头指针，指向队头元素
    int rear;          // 队尾指针，指向队尾元素的下一个位置
} SqQueue;

void InitQueue(SqQueue *Q) {
    if (Q == NULL) {
        printf("Q为null\n");
        return;
    }
    Q->front = Q->rear = 0;
    return;
}

int EnQueue(SqQueue *Q, int x) {
    if ((Q->rear + 1) % MaxSize == Q->front) return 0;

    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    return 1;
}

int DeQueue(SqQueue *Q, int *x) {
    if (Q->rear == Q->front || Q == NULL) return 0;

    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    return 1;
}

int IsEmpty(SqQueue *Q) {
    if (Q == NULL || Q->rear == Q->front) return 1;
    return 0;
}

void BFS(int start, int visited[], int adj[][MAXV], int n) {
    if (start < 0 || start > 10) {
        printf("输入的初始节点位置非法\n");
        return;
    }
    SqQueue Q;
    InitQueue(&Q);
    visited[start] = 1;
    EnQueue(&Q , start);
    while (!IsEmpty(&Q))
    {
        int node;
        DeQueue(&Q, &node);
        printf("%d ", node);

        for (int i = 0; i < n ; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
            EnQueue(&Q, i);
            visited[i] = 1;
            }
        }
    }
    
    return;
}

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