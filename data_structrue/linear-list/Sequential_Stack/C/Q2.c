#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef struct {
    int data[MaxSize];   // 栈空间（静态数组）
    int top;             // 栈顶指针，-1 表示空栈
} SqStack;

void InitStack(SqStack *S) {
    S->top = -1;
    return;
}

int Push(SqStack *S, int x) {
    if (S == NULL) return -1;
    if (S->top == MaxSize - 1) return 0;
    S->data[++S->top] = x;
    return 1;
}

int Pop(SqStack *S, int *x) {
    if (S == NULL) return -1;
    if (S->top == -1) return 0;
    *x = S->data[S->top--];
    return 1;
}

int GetTop(SqStack *S, int *x) {
    if (S == NULL) return -1;
    if (S->top == -1) return 0;
    *x = S->data[S->top];
    return 1;
}

int IsEmpty(SqStack *S) {
    if (S == NULL || S->top == -1) return 1;
    return 0;
}

void PrintStack(SqStack *S) {
    if (S == NULL || S->top == -1) return;
    int bottom = 0;
    while (bottom <= S->top)
    {
        printf("%d " , S->data[bottom]);
        bottom++;
    }
    return;
}

void ReverseArray(int arr[], int n) {
    SqStack S;
    InitStack(&S);
    for (int i = 0; i < n ; i++) {
        int ret = Push(&S , arr[i]);
        if (ret == 0) return;
    }
    int tmp = S.top;
    int index = 0;
    while (tmp > -1) arr[index++] = S.data[tmp--];
    return;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    ReverseArray(arr1, 5);
    printf("反转后: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr1[i]);
    printf("\n预期: 5 4 3 2 1\n");

    int arr2[] = {7};
    ReverseArray(arr2, 1);
    printf("单元素反转: %d（预期 7）\n", arr2[0]);

    return 0;
}