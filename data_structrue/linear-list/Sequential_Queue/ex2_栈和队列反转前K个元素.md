# 练习2：用栈和队列反转前 K 个元素

## 题目

给定一个整数数组和两个整数 `n` 和 `k`，利用**队列**和**栈**将数组的前 `k` 个元素反转，其余元素保持原序。

```
输入: arr = [1, 2, 3, 4, 5], k = 3
过程: 前3个(1,2,3)进入队列→栈反转→回到队列→拼接剩余(4,5)
输出: [3, 2, 1, 4, 5]
```

## 思路

```
1. 前 k 个元素入队
2. 从队中逐个出队，入栈（顺序反转了）
3. 从栈中逐个出栈，重新入队（再次反转 = 恢复原序？不对——再想一下）

     入队: front [1, 2, 3] rear
     出队入栈: 栈顶 [3, 2, 1] 栈底
     出栈重新入队: front [3, 2, 1] rear  ✅ 已经反了
4. 剩余 n-k 个元素直接入队
5. 从队中全部出队写回 arr
```

## 函数签名

```c
void ReverseFirstK(int arr[], int n, int k);
// 前置条件: 1 <= k <= n
```

## 测试用例（C）

```c
int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    ReverseFirstK(arr1, 5, 3);
    printf("反转前3个: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr1[i]);
    printf("\n预期: 3 2 1 4 5\n");

    int arr2[] = {10, 20, 30, 40};
    ReverseFirstK(arr2, 4, 4);
    printf("反转全部: ");
    for (int i = 0; i < 4; i++) printf("%d ", arr2[i]);
    printf("\n预期: 40 30 20 10\n");

    int arr3[] = {7, 8, 9};
    ReverseFirstK(arr3, 3, 1);
    printf("k=1（不变）: ");
    for (int i = 0; i < 3; i++) printf("%d ", arr3[i]);
    printf("\n预期: 7 8 9\n");

    return 0;
}
```

**提示**：调用 ex1 的 `SqQueue` 和之前栈的 `SqStack`，或者自己在这个文件里写简化版。

---

## C++ 版本

### 要求

用 `queue<int>` 和 `stack<int>` 实现 `void ReverseFirstK(vector<int> &arr, int k)`。

### 测试用例（C++）

```cpp
vector<int> v1 = {1, 2, 3, 4, 5};
ReverseFirstK(v1, 3);
cout << "反转前3个: ";
for (int x : v1) cout << x << " ";
cout << "\n预期: 3 2 1 4 5" << endl;

vector<int> v2 = {10, 20, 30, 40};
ReverseFirstK(v2, 4);
cout << "反转全部: ";
for (int x : v2) cout << x << " ";
cout << "\n预期: 40 30 20 10" << endl;

vector<int> v3 = {7, 8, 9};
ReverseFirstK(v3, 1);
cout << "k=1（不变）: ";
for (int x : v3) cout << x << " ";
cout << "\n预期: 7 8 9" << endl;
```
