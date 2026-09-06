#include <iostream>
using namespace std;

// ========== 结构体定义 ==========
struct ListNode {
    int data;
    ListNode *next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// ========== 建表辅助函数（尾插法）==========
ListNode* BuildList(int arr[], int n) {
    if (n <= 0) return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return head;
}

// ========== 打印链表 ==========
void PrintList(ListNode *head) {
    for (ListNode *p = head; p; p = p->next)
        cout << p->data << " ";
}

// ========== 你要实现的函数 ==========
ListNode* SwapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* newhead = head->next;
    ListNode* sub = SwapPairs(head->next->next);

    newhead->next = head;
    head->next = sub;
    return newhead;
}

// ========== 测试 ==========
int main() {
    // 偶数个
    int a1[] = {1, 2, 3, 4};
    ListNode *h1 = BuildList(a1, 4);
    h1 = SwapPairs(h1);
    cout << "偶数个: "; PrintList(h1);
    cout << "\n预期: 2 1 4 3" << endl;

    // 奇数个
    int a2[] = {1, 2, 3};
    ListNode *h2 = BuildList(a2, 3);
    h2 = SwapPairs(h2);
    cout << "奇数个: "; PrintList(h2);
    cout << "\n预期: 2 1 3" << endl;

    // 单节点
    int a3[] = {1};
    ListNode *h3 = BuildList(a3, 1);
    h3 = SwapPairs(h3);
    cout << "单节点: "; PrintList(h3);
    cout << "\n预期: 1" << endl;

    // 空链表
    cout << "空链表: "
         << (SwapPairs(nullptr) == nullptr ? "nullptr ✅" : "❌") << endl;

    return 0;
}