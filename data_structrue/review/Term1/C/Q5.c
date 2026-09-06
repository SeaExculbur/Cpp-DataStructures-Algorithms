#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack *S) {
    S->top = -1;
}

void Push(SqStack *S, int x) {
    if (S->top >= MaxSize - 1) return;
    S->data[++S->top] = x;
    return;
}

void Pop(SqStack *S, int *p) {
    if (S->top <= -1) return;
    *p = S->data[S->top--];
    return;
}

int IsEmpty(SqStack *S) {
    if (S->top <= -1) return 1;
    else return 0;
}

void Gettop(SqStack *S , int *p) {
    if (S == NULL || S->top <= -1) return;
    *p = S->data[S->top];
    return;
}

void NextGreaterElement(int arr[], int n, int result[]) {
    if (n <= 0) {
        printf("n非法\n");
        return;
    }
    for (int i = 0; i < n; i++) result[i] = -1;
    int p;
    SqStack S;
    InitStack(&S);
    for (int i = 0; i < n; i++) {
        while (!IsEmpty(&S)) {
            int idx;
            Gettop(&S, &idx);
            if (arr[idx] >= arr[i]) break;
            Pop(&S, &idx);
            result[idx] = arr[i]; 
        }
    Push(&S, i);
    }
}

int main() {
    int arr1[] = {2, 1, 3, 4, 2};
    int res1[5];
    NextGreaterElement(arr1, 5, res1);
    printf("结果: ");
    for (int i = 0; i < 5; i++) printf("%d ", res1[i]);
    printf("\n预期: 3 3 4 -1 -1\n");

    int arr2[] = {5, 4, 3, 2, 1};   // 递减
    int res2[5];
    NextGreaterElement(arr2, 5, res2);
    printf("递减: ");
    for (int i = 0; i < 5; i++) printf("%d ", res2[i]);
    printf("\n预期: -1 -1 -1 -1 -1\n");

    int arr3[] = {1, 2, 3, 4, 5};   // 递增
    int res3[5];
    NextGreaterElement(arr3, 5, res3);
    printf("递增: ");
    for (int i = 0; i < 5; i++) printf("%d ", res3[i]);
    printf("\n预期: 2 3 4 5 -1\n");

    return 0;
}