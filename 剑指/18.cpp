// 删除链表的节点
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

// Leetcode解决办法
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* p = head;
        ListNode* q = head->next;

        if(p->val == val)
            return q;
        while(q != nullptr)
        {
            if(q->val == val)
            {
                p->next = q->next;
                return head;
            } else
            {
                p = p->next;
                q = q->next;
            }
        }
        return head;
    }
};

int main()
{
    // 遇上不存在的节点，返回原节点
    vector<int> a = {4, 5, 1, 9};
    int val = 10;
    int val2 = 5;

    ListNode* A = new ListNode;
    InitListNode(A, a);
    PrintListNode(A);

    Solution sol;
    ListNode* C = new ListNode;
    C = sol.deleteNode(A, val);
    PrintListNode(C);

    ListNode* D = new ListNode;
    D = sol.deleteNode(A, val2);
    PrintListNode(D);

    return 0;
}