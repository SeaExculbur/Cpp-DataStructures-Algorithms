# 练习2：用栈反转序列

## 题目

利用上题实现的顺序栈，编写函数 `void ReverseArray(int arr[], int n)`，用栈将一个数组原地反转。

## 要求

- 调用 ex1 中的 `SqStack`、`Push`、`Pop`、`InitStack`
- 不能直接用双指针交换（练习的是栈的应用）

## 思路

```
第一步：全部入栈 → arr = [1, 2, 3, 4]
         栈: 栈底 [1, 2, 3, 4] 栈顶

第二步：全部出栈写回 arr → 出栈顺序 4, 3, 2, 1
         arr = [4, 3, 2, 1]  ✅
```

栈是 LIFO（后进先出），放进去再取出来，顺序自然就反了。

## 函数签名

```c
void ReverseArray(int arr[], int n);
```

## main 测试

```c
int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    ReverseArray(arr1, 5);
    printf("反转后: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr1[i]);
    printf("\n预期: 5 4 3 2 1\n");

    int arr2[] = {7};
    ReverseArray(arr2, 1);
    printf("单元素反转: %d（预期 7）\n", arr2[0]);

    return 0;
}
```

---

## C++ 版本

### 知识准备

`stack<int>` + `vector<int>` 混用，出栈写回数组时用 `int &x`（引用）才能修改原数组元素。

### 要求

用 `stack<int>` 实现 `void ReverseArray(vector<int> &arr)`，逻辑和 C 版一致：全部入栈 → 全部出栈写回。

### 测试用例

```cpp
vector<int> v1 = {1, 2, 3, 4, 5};
ReverseArray(v1);
cout << "反转后: ";
for (int x : v1) cout << x << " ";
cout << "\n预期: 5 4 3 2 1" << endl;

vector<int> v2 = {7};
ReverseArray(v2);
cout << "单元素反转: " << v2[0] << "（预期 7）" << endl;
```
