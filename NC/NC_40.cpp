// 链表相加
class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        if (!head1) return head2;
        if (!head2) return head1;
        stack<int> s1, s2;
        while (head1) {
            s1.push(head1->val);
            head1 = head1->next;
        }
        while (head2) {
            s2.push(head2->val);
            head2 = head2->next;
        }
        ListNode* res = nullptr;
        ListNode* cur = res;
        int carry = 0;
        while (!s1.empty() || !s2.empty()) {
            int tempValue = carry;
            if (!s1.empty()) {
                tempValue += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                tempValue += s2.top();
                s2.pop();
            }
            int nodeValue = tempValue % 10;
            carry = tempValue / 10;
            cur = new ListNode(nodeValue);
            cur->next = res;
            res = cur;
        }
        if (carry) {
            cur = new ListNode(1);
            cur->next = res;
            res = cur;
        }
        return res;
    }
};