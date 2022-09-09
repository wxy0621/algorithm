// 两数相加 II
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        stack<int> s1, s2;
        ListNode* res = nullptr;
        while(l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        while(!s1.empty() || !s2.empty() || carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
            int sum = a + b + carry;
            carry = (a + b + carry) / 10;
            sum %= 10;
            ListNode* cur = new ListNode(sum);
            cur->next = res;
            res = cur;
        }
        return res;
    }
};