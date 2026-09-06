#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef struct {
    int top;
    char data[MaxSize];
} CharStack;

void initstack(CharStack *S) {
    if (S == NULL) {
        return;
    }
    S->top = -1;
}

int Push(CharStack *S, char c) {
    if (S == NULL || S->top == MaxSize - 1) {
        printf("栈满或S指向NULL\n");
        return 0;
    }
    S->data[++S->top] = c;
    return 1;
}

int Pop(CharStack *S, char *c) {
    if (S == NULL || S->top == -1) {
        printf("栈空或S指向NULL\n");
        return 0;
    }
    *c = S->data[S->top--];
    return 1;
}

int GetTop(CharStack *S, int *x) {
    if (S == NULL || S->top <= -1) {
        printf("栈空或者S指向NULL\n");
        return 0;
    }

    *x = S->data[S->top];
    return 1;
}

int IsEmpty(CharStack *S) {
    if (S == NULL || S->top <= -1) {
        printf("栈空或者S指向NULL\n");
        return 1;
    }
    return 0;
}

void PrintStack(CharStack *S) {
    if (S == NULL || S->top <= -1) {
        printf("栈空或者S指向NULL\n");
        return;
    }

    for (int i = 0 ; i <= S->data[S->top] ; i++) {
        printf("%d " ,S->data[i]);
    }
    return;
}

int IsBracketMatch(char *str) {
    CharStack S;
    initstack(&S);

    for (int i = 0; str[i] != '\0' ;i++)
    {
        if (S.top == MaxSize - 1) {
            printf("栈满\n");
            return 0;
        }

        char ch = str[i];
        if (ch == '{' || ch == '(' || ch == '[') {
        int ret = Push(&S , str[i]);
        if (ret == 0) return 0;
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (IsEmpty(&S)) return 0;

            char topc;
            Pop(&S , &topc);
            if (ch == ')' && topc != '(') return 0;
            if (ch == ']' && topc != '[') return 0;
            if (ch == '}' && topc != '{') return 0;
        }
    }
    
    return IsEmpty(&S);
}

int main() {
    char *tests[] = {
        "()",
        "()[]{}",
        "{[()]}",
        "{[]()}",
        "(]",
        "([)]",
        "(",
        ")",
        ""
    };
    int expected[] = {1, 1, 1, 1, 0, 0, 0, 0, 1};

    for (int i = 0; i < 9; i++) {
        int result = IsBracketMatch(tests[i]);
        printf("\"%s\" → %d（预期 %d）%s\n",
               tests[i], result, expected[i],
               result == expected[i] ? "✅" : "❌");
    }
    return 0;
}