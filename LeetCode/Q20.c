#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isValid(char* s) {
    int top = -1;
    char *data = (char *)malloc(strlen(s));
    for (int i = 0 ; s[i] != '\0' ;i++) {

        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            data[++top] = ch;
        }

        else if (ch == ')' || ch == ']' || ch == '}') {    
            if (top == -1 ) return false;
            char leftchar = data[top];
            top--;
            if (leftchar == '(' && ch != ')') return false;
            if (leftchar == '[' && ch != ']') return false;
            if (leftchar == '{' && ch != '}') return false;
        }
    }
    return top == -1;
}