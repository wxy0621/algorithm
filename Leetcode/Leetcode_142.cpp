// 环形链表II
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        do {
            if(fast == nullptr || fast->next == nullptr)
                return nullptr;
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        } while(fast != slow);
        fast = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main()
{
    
    return 0;
}