#include <stdio.h>

#define MaxSize 6      // 实际最多存 MaxSize-1 = 5 个元素

typedef struct {
    int data[MaxSize];
    int front;         // 队头指针，指向队头元素
    int rear;          // 队尾指针，指向队尾元素的下一个位置
} SqQueue;

typedef struct {
    int top;
    int data[MaxSize];
} SqStack;

// ----------队列------------
void InitQueue(SqQueue *Q) {
    Q->front=Q->rear=0;
    return;
}

int EnQueue(SqQueue *Q, int x) {
    if ((Q->rear + 1) % MaxSize == Q->front || Q == NULL) return 0;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    return 1;
}

int DeQueue(SqQueue *Q, int *x) {
    if (Q == NULL || Q->front == Q->rear) return 0;
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    return 1;
}

int GetHead(SqQueue *Q, int *x) {
    if (Q == NULL || Q->rear == Q->front) return 0;
    *x = Q->data[Q->front];
    return 1;
}

int IsEmpty(SqQueue *Q) {
    if (Q == NULL || Q->rear == Q->front) return 1;
    return 0;
}

int QueueLength(SqQueue *Q) {
    if (Q == NULL || Q->rear == Q->front) return 0;
    return (Q->rear - Q->front + MaxSize ) % MaxSize;
}

// --------栈----------

void InitStack(SqStack *S) {
    if (S == NULL) {
        printf("S指向空\n");
        return;
    }
    S->top = -1;
    return;
}

int Push(SqStack *S, int x) {
    if (S->top == MaxSize - 1) {
        printf("栈满\n");
        return 0;
    }
    S->data[++S->top] = x;
    return 1;
}

int Pop(SqStack *S, int *x) {
    if (S->top == -1) {
        printf("栈空\n");
        return 0;
    }
    *x = S->data[S->top--];
    return 1;
}

int GetTop(SqStack *S, int *x) {
    if (S->top == -1) {
        printf("栈空\n");
        return 0;
    }
    *x = S->data[S->top];
    return 1;
}

void ReverseFirstK(int arr[], int n, int k) {
    // 前置条件: 1 <= k <= n
    if (k < 1 || k > n) return;

    SqStack S;
    InitStack(&S);
    SqQueue Q;
    InitQueue(&Q);
    for (int i = 0 ; i < n ; i++) {
        int ret = EnQueue(&Q , arr[i]);
        if (!ret) return;
    }
    int res;
    for (int j = 0 ; j < k ; j++) {
        int ret = DeQueue(&Q , &res);
        if (ret == 0) return;
        if (!Push(&S , res)) return;
    }
    while (S.top != -1)
    {
        Pop(&S, &res);
        int ret = EnQueue(&Q, res);
        if (!ret) return;
    }
    
    int index = 0;
    while (!IsEmpty(&Q))
    {
        DeQueue(&Q, &res);
        arr[index++] = res;
    }
    
    return;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    ReverseFirstK(arr1, 5, 3);
    printf("反转前3个: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr1[i]);
    printf("\n预期: 3 2 1 4 5\n");

    int arr2[] = {10, 20, 30, 40};
    ReverseFirstK(arr2, 4, 4);
    printf("反转全部: ");
    for (int i = 0; i < 4; i++) printf("%d ", arr2[i]);
    printf("\n预期: 40 30 20 10\n");

    int arr3[] = {7, 8, 9};
    ReverseFirstK(arr3, 3, 1);
    printf("k=1（不变）: ");
    for (int i = 0; i < 3; i++) printf("%d ", arr3[i]);
    printf("\n预期: 7 8 9\n");

    return 0;
}