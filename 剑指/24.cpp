// 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode* reverse = nullptr;
        ListNode* node = head;
        ListNode* prev = nullptr;

        while(node != nullptr)
        {
            ListNode* next = node->next;
            if(next == nullptr)
                reverse = node;
            node->next = prev;
            prev = node;
            node = next;
        }
        return reverse;
    }
};

int main()
{
    vector<int> a = {1, 2, 4, 5, 6};

    ListNode* A = new ListNode;
    InitListNode(A, a);
    PrintListNode(A);

    Solution sol;
    ListNode* C = new ListNode;
    C = sol.reverseList(A);
    PrintListNode(C);

    return 0;
}