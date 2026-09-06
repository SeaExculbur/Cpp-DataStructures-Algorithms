#include <stdlib.h>
#include <stdio.h>

#define MaxSize 1000   // 最多存储100-1

typedef struct BiTNode
{
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
}BiTNode ,*BiTree;

typedef struct {
    BiTNode *data[MaxSize];
    int front;         // 队头指针，指向队头元素
    int rear;          // 队尾指针，指向队尾元素的下一个位置
} SqQueue;

// 队列操作
void InitQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return;
}

void EnQueue(SqQueue *Q ,BiTNode *x) {
    if (Q == NULL || (Q->rear + 1) % MaxSize == Q->front) return;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    return;
}

BiTNode *DeQueue(SqQueue *Q) {
    if (Q == NULL || (Q->front == Q->rear)) return NULL;
    BiTNode *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    return x;
}

int IsEmpty(SqQueue *Q) {
    if (Q == NULL || Q->front == Q->rear) return 1;
    return 0;
}

// 二叉树初始化
BiTNode *CreateNode(int data) {
    BiTNode *tn = (BiTNode *)malloc(sizeof(BiTNode));
    if (tn == NULL) {
        printf("内存不足，节点分配失败\n");
        return NULL;
    }
    tn->data = data;
    tn->left = NULL;
    tn->right = NULL;
    return tn;
}

void LevelOrder(BiTNode *root) {
    if (root == NULL) return;
    SqQueue Q;
    InitQueue(&Q);
    BiTree p;
    EnQueue(&Q , root);
    while (!IsEmpty(&Q))
    {
        p = DeQueue(&Q);
        printf("%d ", p->data);
        if (p->left != NULL)
            EnQueue(&Q , p->left);
        if (p->right != NULL)
            EnQueue(&Q, p->right);
    }
    return;
}

// 同一棵树
int main() {
    BiTNode *root = CreateNode(1);
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