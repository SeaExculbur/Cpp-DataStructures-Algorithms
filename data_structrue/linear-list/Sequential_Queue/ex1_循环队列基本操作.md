# 练习1：循环队列基本操作

## 背景

普通队列用数组实现时，出队后前面的空间会浪费（假溢出）。循环队列用取模运算让队尾绕回数组头部，空间重复利用。

## 核心约定

```
入队：rear = (rear + 1) % MaxSize  →  data[rear] = x
出队：front = (front + 1) % MaxSize →  data[front] 是出队元素

初始：front = 0, rear = 0（空队列）
判空：front == rear
判满：(rear + 1) % MaxSize == front  ← 牺牲一个位置来区分空和满
```

## 结构体定义

```c
#define MaxSize 6      // 实际最多存 MaxSize-1 = 5 个元素
typedef struct {
    int data[MaxSize];
    int front;         // 队头指针，指向队头元素
    int rear;          // 队尾指针，指向队尾元素的下一个位置
} SqQueue;
```

## 需要实现的函数

| 函数 | 功能 | 返回值 |
|------|------|--------|
| `void InitQueue(SqQueue *Q)` | 初始化空队列（`front = rear = 0`） | 无 |
| `int EnQueue(SqQueue *Q, int x)` | 入队 | 成功 1，队满 0 |
| `int DeQueue(SqQueue *Q, int *x)` | 出队，值通过 `x` 带出 | 成功 1，队空 0 |
| `int GetHead(SqQueue *Q, int *x)` | 读队头，不出队 | 成功 1，队空 0 |
| `int IsEmpty(SqQueue *Q)` | 判空 | 空 1，非空 0 |
| `int QueueLength(SqQueue *Q)` | 返回当前元素个数 | 公式：`(rear - front + MaxSize) % MaxSize` |

## 测试用例（C）

```c
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
```

---

## C++ 版本

### 知识准备

```cpp
#include <queue>
queue<int> q;         // 声明，等价 C 的整个 SqQueue 结构体
```

| C（手写） | C++ `queue<T>` |
|-----------|----------------|
| `SqQueue Q; InitQueue(&Q);` | `queue<int> q;` |
| `EnQueue(&Q, x)` | `q.push(x)` |
| `DeQueue(&Q, &x)` | `x = q.front(); q.pop();`（**两步！pop() 只移除不返回值**） |
| `GetHead(&Q, &x)` | `x = q.front()` |
| `IsEmpty(&Q)` | `q.empty()` |
| 队满判断 | 不需要，自动扩容 |

### 要求

用 `queue<int>` 实现和 C 版本相同的测试用例，不手写任何结构体。

### 测试用例（C++）

```cpp
queue<int> q;

// 1. 判空
cout << "空队列: empty=" << q.empty() << "（预期 1）" << endl;

// 2. 入队 10, 20, 30, 40, 50
q.push(10); q.push(20); q.push(30); q.push(40); q.push(50);
cout << "队头=" << q.front() << "（预期 10）" << endl;
cout << "队尾=" << q.back() << "（预期 50）" << endl;
cout << "size=" << q.size() << "（预期 5）" << endl;

// 3. 出队两个
q.pop();
q.pop();
cout << "出队两次后队头=" << q.front() << "（预期 30）" << endl;

// 4. 循环出队全部
cout << "全部出队: ";
while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
}
cout << "\n预期: 30 40 50" << endl;

// 5. 空队出队（queue 的 pop 在空时是未定义行为，先判空！）
cout << "空队 empty=" << q.empty() << "（预期 1）" << endl;
```
