// 链表中倒数第k个节点
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

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(head == nullptr || n == 0)
        return nullptr;
    ListNode* before = head;
    ListNode* behind = head;

    for(int i = 0; i < n-1; ++i)
    {
        if(before->next != nullptr)
            before = before->next;
        else
            return nullptr;
    }

    // behind = head;

    while(before->next != nullptr)
    {
        before = before->next;
        behind = behind->next;
    }
    return behind;
}

// 简便版
class Solution2 {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(k--) fast = fast->next;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

// 简便版的情况补充
class Solution3 {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && k-- > 0) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main()
{
    vector<int> a = {4, 5, 1, 9, 10, 3};
    int val = 2;

    ListNode* A = new ListNode;
    InitListNode(A, a);
    PrintListNode(A);

    ListNode* C = new ListNode;
    C = removeNthFromEnd(A, val);
    PrintListNode(C);

    return 0;
}