# 练习3：就地反转单链表

## 题目

编写函数 `void List_Reverse(LinkList L)`，将带头结点的单链表**就地逆置**。

- **就地**：不申请新节点，只修改指针方向
- 空间复杂度 O(1)
- 头结点保留不动，只反转数据节点之间的链接方向

## 反转示意

```
反转前：  L → 10 → 20 → 30 → 40 → NULL
反转后：  L → 40 → 30 → 20 → 10 → NULL
```

## 核心思路（三指针法）

使用三个指针遍历链表，逐个反向节点的 `next`：

```
      prev   cur    next
       ↓      ↓      ↓
  L →  A  →   B  →   C  → NULL

每一步：
  1. next = cur->next;    // 保存下一个节点
  2. cur->next = prev;    // 反转：当前节点指向前一个
  3. prev = cur;          // 三指针整体右移
  4. cur = next;

循环结束后：
  L->next = prev;         // 头结点指向新的首节点（原尾节点）
```

## 结构体定义（参考）

```c
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;
```

## 测试用例

| 用例 | 反转前 | 反转后 |
|------|--------|--------|
| 多节点 | `10 -> 20 -> 30 -> 40` | `40 -> 30 -> 20 -> 10` |
| 单节点 | `5` | `5` |
| 空表 | （空表） | （空表） |

## 需要实现的函数

1. `void InitList(LinkList *L)` — 建立头结点
2. `void BuildList(LinkList L, int arr[], int n)` — 尾插法批量建表
3. `void List_Reverse(LinkList L)` — **核心函数**，就地反转
4. `void PrintList(LinkList L)` — 打印链表
5. `void DestroyList(LinkList *L)` — 销毁链表
