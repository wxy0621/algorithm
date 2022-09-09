// 两数相加
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = carry + n1 + n2;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry)
            cur->next = new ListNode(1);
        return res->next;
    }
};

int main()
{
    
    return 0;
}