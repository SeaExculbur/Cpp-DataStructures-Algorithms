# 练习4：查找倒数第 k 个节点

## 题目

编写函数 `LNode* List_FindKthFromEnd(LinkList L, int k)`，返回带头结点单链表中**倒数第 k 个**数据节点的指针。

- 只能遍历链表**一次**（时间复杂度 O(n)）
- 空间复杂度 O(1)
- 如果 k 非法（`k <= 0` 或 k 超出表长），返回 `NULL`

## 核心思路（快慢指针 / 双指针）

1. **快指针 `fast`** 先向前走 k 步
2. 然后**慢指针 `slow`** 和 `fast` 同步前进
3. 当 `fast` 走到 `NULL` 时，`slow` 正好在倒数第 k 个位置

### 图解（找倒数第 2 个，k=2）

**步骤1：fast 先走 2 步**

```
 slow       fast
  ↓          ↓
L → [10] → [20] → [30] → NULL
```

**步骤2：同步前进，fast=NULL 时停止**

```
                  slow    fast(NULL)
                   ↓       ↓
L → [10] → [20] → [30] → NULL
           ↑
      倒数第2个！返回指向 20 的指针
```

## 结构体定义（参考）

```c
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;
```

## 测试用例

链表：`10 -> 20 -> 30 -> 40 -> 50`

| k | 预期结果 |
|---|----------|
| 1 | 返回指向 `50` 的指针（倒数第1个） |
| 3 | 返回指向 `30` 的指针（倒数第3个） |
| 5 | 返回指向 `10` 的指针（倒数第5个，即正数第1个） |
| 6 | 返回 `NULL`（超出表长） |
| 0 | 返回 `NULL`（非法输入） |

## 需要实现的函数

1. `void InitList(LinkList *L)` — 建立头结点
2. `void BuildList(LinkList L, int arr[], int n)` — 尾插法批量建表
3. `LNode* List_FindKthFromEnd(LinkList L, int k)` — **核心函数**，查找倒数第 k 个节点
4. `void PrintList(LinkList L)` — 打印链表
5. `void DestroyList(LinkList *L)` — 销毁链表
