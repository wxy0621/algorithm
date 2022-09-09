//  两两交换链表中的节点
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = new ListNode(0);
        ListNode* p = res;

        p->next = head;

        while(head != nullptr && head->next != nullptr) {
            ListNode* first = head;
            ListNode* second = head->next;

            //交换，通过画图节点交换更明显
            p->next = second;
            first->next = second->next;
            second->next = first;

            p = first;
            head = first->next;
        }
        return res->next;
    }
};

int main()
{
    
    return 0;
}