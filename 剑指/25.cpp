// 字节电话面试题，合并两个有序链表
#include <bits/stdc++.h>

using namespace std;

// 链表结构体
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// 顺序遍历链表
void PrintListNode(ListNode* l1)
{
    ListNode* current = l1;
    while(current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// 初始化链表，通过vector
void InitListNode(ListNode* A, vector<int> a)
{
    A->val = a[0];
    A->next = nullptr;
    for(int i = 1; i < a.size(); ++i)
    {
        ListNode* A2 = new ListNode;
        A2->val = a[i];
        A2->next = nullptr;
        A->next = A2;
        A = A2;
    }
}

// 递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        else if(l2 == nullptr)
            return l1;
        
        ListNode* res = nullptr;

        if(l1->val < l2->val)
        {
            res = l1;
            res->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            res = l2;
            res->next = mergeTwoLists(l1, l2->next);
        }
        return res;
    }
};

// 迭代
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        if(!l1) cur->next = l2;
        if(!l2) cur->next = l1;
        return res->next;
    }
};

int main()
{
    vector<int> a = {1, 2, 4};
    vector<int> b = {1, 3, 4};

    ListNode* A = new ListNode;
    InitListNode(A, a);
    PrintListNode(A);
    
    ListNode* B = new ListNode;
    InitListNode(B, b);
    PrintListNode(B);

    Solution sol;
    ListNode* C = new ListNode;
    C = sol.mergeTwoLists(A, B);
    PrintListNode(C);

    return 0;
}