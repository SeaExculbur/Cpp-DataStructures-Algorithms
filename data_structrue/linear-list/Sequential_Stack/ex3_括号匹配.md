# 练习3：括号匹配

## 题目

编写函数 `int IsBracketMatch(char *str)`，判断一个字符串中的括号是否正确匹配。

只考虑三种括号：`()` `[]` `{}`

## 规则

- 每个左括号必须有同类型的右括号闭合
- 闭合顺序必须正确——先开的必须后闭

```
✅ 正确:  "()"    "()[]{}"   "{[()]}"   "{[]()}"
❌ 错误:  "(]"     "([)]"    "("        ")"
```

## 思路

把 ex1 的顺序栈改造成 `char` 类型（`data` 元素类型改为 `char`）：

```
从左到右扫描字符:
  遇到 '(' '[' '{' → 入栈
  遇到 ')' ']' '}' → 栈顶必须是匹配的左括号 → 出栈
                     否则不匹配

全部扫描完 → 栈必须是空的
```

## 顺序栈改造（char 版）

```c
#define MaxSize 100
typedef struct {
    char data[MaxSize];
    int top;
} CharStack;

void InitStack(CharStack *S) { S->top = -1; }
int  Push(CharStack *S, char c) { ... }
int  Pop(CharStack *S, char *c) { ... }
int  IsEmpty(CharStack *S) { return S->top == -1; }
```

## 函数签名

```c
int IsBracketMatch(char *str);   // 正确返回 1，错误返回 0
```

## main 测试

```c
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
```

---

## C++ 版本

### 知识准备

`stack<char>` + `string`。`string` 可以用范围 for 遍历，用 `str[i]` 取字符，`==` 比较，和 `char[]` 用法几乎一样。`pop()` 只移除不返回值——先 `top()` 取，再 `pop()` 弹。

### 要求

用 `stack<char>` 实现 `bool IsBracketMatch(string str)`，逻辑和 C 版一致。

### 测试用例

```cpp
string tests[] = {
    "()", "()[]{}", "{[()]}", "{[]()}",
    "(]", "([)]", "(", ")", ""
};
bool expected[] = {1, 1, 1, 1, 0, 0, 0, 0, 1};

for (int i = 0; i < 9; i++) {
    bool result = IsBracketMatch(tests[i]);
    cout << "\"" << tests[i] << "\" -> " << result
         << " (预期 " << expected[i] << ") "
         << (result == expected[i] ? "✅" : "❌") << endl;
}
```

