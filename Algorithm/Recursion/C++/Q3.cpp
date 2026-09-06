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
ListNode* ReverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *p = ReverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}

// ========== 测试 ==========
int main() {
    // 多节点
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode *head = BuildList(arr1, 5);
    head = ReverseList(head);
    cout << "反转后: ";
    PrintList(head);
    cout << "\n预期: 5 4 3 2 1" << endl;

    // 单节点
    int arr2[] = {7};
    ListNode *single = BuildList(arr2, 1);
    single = ReverseList(single);
    cout << "单节点: " << single->data << " (预期 7)" << endl;

    // 空链表
    cout << "空链表: " << (ReverseList(nullptr) == nullptr ? "nullptr ✅" : "❌") << endl;

    return 0;
}