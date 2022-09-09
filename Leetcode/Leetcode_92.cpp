// 反转链表II
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        for(int i = 1; i < m; ++i) {
            pre = pre->next;
        }
        head = pre->next;
        // 画图好理解
        for(int i = m; i < n; ++i) {
            ListNode* nex = head->next;
            head->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
        }
        return dummy->next;
    }
};

int main()
{
    
    return 0;
}