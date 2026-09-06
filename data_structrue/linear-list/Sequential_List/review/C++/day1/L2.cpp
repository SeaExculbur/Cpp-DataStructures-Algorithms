#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ===== vector<int> 等价于你手写的整个 Sqlist 结构体 =====

    // 1. 创建空向量
    //    C: Sqlist L; initlist(&L);
    vector<int> v;
    cout << "1. 空向量, size=" << v.size() << endl;

    // 2. push_back = 尾插
    //    C: ListInsert(&L, L.length+1, 10);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    cout << "2. 尾插后: ";
    for (int x : v) cout << x << " ";
    cout << "| size=" << v.size() << endl;

    // 3. 直接初始化
    //    C: int arr[]={1,2,3}; buildList(&L, arr, 3);
    vector<int> v2 = {1, 2, 3, 4, 5};
    cout << "3. 直接初始化: ";
    for (int x : v2) cout << x << " ";
    cout << endl;

    // 4. 按位置插入（自动后移）
    //    C: ListInsert(&L, 2, 99);  + 手写后移循环
    v.insert(v.begin() + 2, 99);
    cout << "4. 在下标2插入99: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // 5. 按位置删除（自动前移）
    //    C: ListDelete(&L, 3, &deleted);  + 手写前移循环
    v.erase(v.begin() + 3);
    cout << "5. 删除下标3: ";
    for (int x : v) cout << x << " ";
    cout << "| size=" << v.size() << endl;

    // 6. 清空
    //    C: L.length = 0;
    v.clear();
    cout << "6. 清空后: size=" << v.size();
    cout << (v.empty() ? " (空)" : " (非空)") << endl;

    // 7. 不需要 IncreaseSize —— vector 自动扩容

    // 8. 不需要 destroyList —— vector 自动释放内存

    return 0;
}

/*
 * 你手写的 C 代码 (100+ 行)     vs    vector 一行搞定
 * ==========================================================
 * initlist(L)                 ->    vector<int> v;
 * buildList(L, arr, n)        ->    vector<int> v = {1,2,3};
 * ListInsert(L, pos, val)     ->    v.insert(v.begin()+pos, val);
 * ListDelete(L, pos, &del)    ->    v.erase(v.begin()+pos);
 * IncreaseSize(L, len)        ->    自动，不需要写
 * destroyList(L)              ->    自动，不需要写
 * L.length                    ->    v.size()
 * L.length == 0               ->    v.empty()
 */