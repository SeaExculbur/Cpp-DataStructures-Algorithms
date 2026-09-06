# 练习1：顺序栈基本操作

## 结构体定义

```c
#define MaxSize 10
typedef struct {
    int data[MaxSize];   // 栈空间（静态数组）
    int top;             // 栈顶指针，-1 表示空栈
} SqStack;
```

`top` 约定：`top == -1` 时栈空，`top == MaxSize-1` 时栈满。入栈时 `top++`，出栈时 `top--`。

## 需要实现的函数

| 函数 | 功能 | 返回值 |
|------|------|--------|
| `void InitStack(SqStack *S)` | 初始化为空栈（`top = -1`） | 无 |
| `int Push(SqStack *S, int x)` | 入栈 | 成功 1，栈满 0 |
| `int Pop(SqStack *S, int *x)` | 出栈，值通过 `x` 带出 | 成功 1，栈空 0 |
| `int GetTop(SqStack *S, int *x)` | 读栈顶，不出栈 | 成功 1，栈空 0 |
| `int IsEmpty(SqStack *S)` | 判空 | 空 1，非空 0 |
| `void PrintStack(SqStack *S)` | 从栈底到栈顶打印 | 无 |

## 测试用例（写在 main 中）

```c
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
```

## 栈操作示意图

```
初始:  top = -1     []
push(10): top = 0   [10]
push(20): top = 1   [10, 20]
push(30): top = 2   [10, 20, 30]
pop():    top = 1   [10, 20]       返回值 30
pop():    top = 0   [10]           返回值 20
pop():    top = -1  []             返回值 10
pop():    栈空，返回 0
```

---

## C++ 版本

### 知识准备

```cpp
#include <stack>
stack<int> s;         // 声明，等价 C 的整个 SqStack 结构体
```

| C（手写） | C++ `stack<T>` |
|-----------|----------------|
| `SqStack S; InitStack(&S);` | `stack<int> s;` |
| `Push(&S, x)` | `s.push(x)` |
| `Pop(&S, &x)` | `x = s.top(); s.pop();`（**两步！pop() 只移除不返回值**） |
| `GetTop(&S, &x)` | `x = s.top()` |
| `IsEmpty(&S)` | `s.empty()` |
| 栈满判断 | 不需要，自动扩容 |

### 要求

用 `stack<int>` 实现和 C 版本相同的测试用例，所有操作用 STL 方法，不手写任何结构体或函数。

### 测试用例

```cpp
stack<int> s;

// 1. 判空
cout << "空栈: empty=" << s.empty() << "（预期 1）" << endl;

// 2. 入栈 10, 20, 30
s.push(10); s.push(20); s.push(30);
cout << "栈顶=" << s.top() << "（预期 30）" << endl;
cout << "size=" << s.size() << "（预期 3）" << endl;

// 3. 出栈一个
s.pop();
cout << "出栈后栈顶=" << s.top() << "（预期 20）" << endl;

// 4. 全出
s.pop(); s.pop();
cout << "全出后 empty=" << s.empty() << "（预期 1）" << endl;
```
