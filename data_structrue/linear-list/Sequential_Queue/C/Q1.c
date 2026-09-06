#include <stdio.h>

#define MaxSize 6      // 实际最多存 MaxSize-1 = 5 个元素
typedef struct {
    int data[MaxSize];
    int front;         // 队头指针，指向队头元素
    int rear;          // 队尾指针，指向队尾元素的下一个位置
} SqQueue;

void InitQueue(SqQueue *Q) {
    if (Q == NULL) {
        return;
    }
    Q->front = 0;
    Q->rear = 0;
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

int GetHead(SqQueue *Q, int *x) {
    if (Q == NULL || Q->front == Q->rear) return 0;
    *x = Q->data[Q->front];
    return 1;
}

int IsEmpty(SqQueue *Q) {
    if (Q == NULL || Q->rear == Q->front) return 1;
    return 0;
}

int QueueLength(SqQueue *Q) {
    if (Q == NULL || Q->front == Q->rear) return 0;
    return (Q->rear - Q->front + MaxSize) % MaxSize;
}

int main() {
    SqQueue Q;
    int x;
    InitQueue(&Q);

    // 1. 判空
    printf("空队列: IsEmpty=%d（预期 1）\n", IsEmpty(&Q));

    // 2. 入队 10, 20, 30, 40, 50
    EnQueue(&Q, 10);
    EnQueue(&Q, 20);
    EnQueue(&Q, 30);
    EnQueue(&Q, 40);
    EnQueue(&Q, 50);   // 此时队满（5个元素，MaxSize=6，牺牲1个）
    printf("入队5个后: length=%d（预期 5）\n", QueueLength(&Q));

    // 3. 队满时再入队
    printf("队满入队返回=%d（预期 0）\n", EnQueue(&Q, 999));

    // 4. 出队
    DeQueue(&Q, &x);
    printf("出队=%d（预期 10）\n", x);
    DeQueue(&Q, &x);
    printf("出队=%d（预期 20）\n", x);

    // 5. 读队头
    GetHead(&Q, &x);
    printf("队头=%d（预期 30）\n", x);

    // 6. 入队再出队（验证循环：放满后出两个再进两个）
    EnQueue(&Q, 60);
    EnQueue(&Q, 70);
    printf("入队60,70后: length=%d（预期 5）\n", QueueLength(&Q));
    printf("循环出队: ");
    while (!IsEmpty(&Q)) {
        DeQueue(&Q, &x);
        printf("%d ", x);
    }
    printf("\n预期: 30 40 50 60 70\n");

    // 7. 队空出队
    printf("空队出队返回=%d（预期 0）\n", DeQueue(&Q, &x));

    return 0;
}