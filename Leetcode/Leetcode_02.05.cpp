// 链表求和
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while(l1 || l2 || carry) {
            int sum = 0;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            ListNode* temp = new ListNode(sum % 10);
            carry = sum / 10;
            cur->next = temp;
            cur = cur->next;
        }
        return res->next;
    }
};