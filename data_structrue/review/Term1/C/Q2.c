#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef struct SqStack {
    int data[MaxSize];
    int top;
    int bottom;
} SqStack;

typedef struct {
    SqStack stack1;
    SqStack stack2;
} MyQueue;

void InitQueue(MyQueue *q) {
    if (q == NULL) return;
    q->stack1.top = q->stack1.bottom = 0;
    q->stack2.top = q->stack2.bottom = 0;
    return;
}

void EnQueue(MyQueue *q, int x) {
    if (q == NULL) return;
    int q1_top = q->stack1.top;
    int q2_top = q->stack2.top;
    int q1_data = q->stack1.data;
}

int main() {
    MyQueue q;
    InitQueue(&q);
    int x;

    EnQueue(&q, 10);
    EnQueue(&q, 20);
    EnQueue(&q, 30);

    DeQueue(&q, &x);
    printf("出队=%d（预期 10）\n", x);
    DeQueue(&q, &x);
    printf("出队=%d（预期 20）\n", x);

    EnQueue(&q, 40);
    DeQueue(&q, &x);
    printf("出队=%d（预期 30）\n", x);
    DeQueue(&q, &x);
    printf("出队=%d（预期 40）\n", x);

    printf("空队出队返回=%d（预期 0）\n", DeQueue(&q, &x));

    return 0;
}