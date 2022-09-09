// 删除排序链表中的重复元素II
// 三指针法
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = new ListNode(0);
        p->next = head;
        head = p;
        ListNode *left, *right;
        while(p->next) {
            left = p->next;
            right = left;
            while(right->next && right->next->val == right->val)
                right = right->next;
            if(left == right)
                p = p->next;
            else
                p->next = right->next;
        }
        return head->next;
    }
};

int main()
{
    
    return 0;
}