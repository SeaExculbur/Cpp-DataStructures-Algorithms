# 练习2：删除链表中所有值为 x 的节点

## 题目

编写函数 `void List_DeleteValue(LinkList L, int x)`，删除带头结点单链表中**所有** `data == x` 的数据节点，并释放被删节点的内存。

## 要求

1. 带头结点，头结点不会被删除
2. 删除**所有**匹配的节点，不只是第一个
3. 释放被删节点的内存（`free`）

## 核心思路

删除节点时需要知道它的**前驱节点**：

- 如果 `p->data == x`：前驱跳过当前节点，释放 p，p 指向下一个
- 如果 `p->data != x`：前驱和 p 都后移一步

```
pre->next = p->next;   // 前驱跳过当前节点
free(p);               // 释放当前节点
p = pre->next;         // p 继续指向下一个待检查节点
```

## 结构体定义（参考）

```c
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;
```

## 测试用例

链表初始为：`10 -> 20 -> 30 -> 20 -> 40 -> 20 -> 50`

| 操作 | 预期结果 |
|------|----------|
| 删除 `20` | `10 -> 30 -> 40 -> 50` |
| 再删除 `99`（不存在） | `10 -> 30 -> 40 -> 50`（不变） |
| 再删除 `10`（首元素） | `30 -> 40 -> 50` |
| 再删除 `50`（尾元素） | `30 -> 40` |

## 需要实现的函数

1. `void InitList(LinkList *L)` — 建立头结点
2. `void BuildList(LinkList L, int arr[], int n)` — 尾插法批量建表（方便测试）
3. `void List_DeleteValue(LinkList L, int x)` — **核心函数**，删除所有值为 x 的节点
4. `void PrintList(LinkList L)` — 打印链表
5. `void DestroyList(LinkList *L)` — 销毁链表
