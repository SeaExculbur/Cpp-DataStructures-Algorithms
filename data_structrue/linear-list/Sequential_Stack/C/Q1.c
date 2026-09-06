#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef struct {
    int data[MaxSize];   // 栈空间（静态数组）
    int top;             // 栈顶指针，-1 表示空栈
} SqStack;

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

int IsEmpty(SqStack *S) {
    if (S->top == -1) return 1;
    return 0;
}

void PrintStack(SqStack *S) {
    if (S->top == -1) {
        printf("栈空\n");
        return;
    }
    int bottom = 0;
    while (bottom <= S->top)
    {
        printf("%d " , S->data[bottom++]);
    }
    return;
}

int main() {
    SqStack S;
    int x;

    InitStack(&S);
    printf("空栈: IsEmpty=%d（预期 1）\n", IsEmpty(&S));

    // 入栈 10, 20, 30
    Push(&S, 10); Push(&S, 20); Push(&S, 30);
    printf("栈底到栈顶: "); PrintStack(&S);
    printf("预期: 10 20 30\n");

    // 读栈顶
    GetTop(&S, &x);
    printf("栈顶=%d（预期 30）\n", x);

    // 出栈
    Pop(&S, &x);
    printf("出栈=%d（预期 30），剩余: ", x); PrintStack(&S);
    printf("预期: 10 20\n");

    Pop(&S, &x);
    Pop(&S, &x);
    printf("全出后 IsEmpty=%d（预期 1）\n", IsEmpty(&S));

    // 栈空时出栈
    int ret = Pop(&S, &x);
    printf("空栈出栈返回=%d（预期 0）\n", ret);

    // 填满再入栈
    for (int i = 0; i < MaxSize; i++) Push(&S, i);
    printf("满栈入栈返回=%d（预期 0）\n", Push(&S, 999));

    return 0;
}