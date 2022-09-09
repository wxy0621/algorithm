// 奇偶链表
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* head_e = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;
        while(even && even->next) {
            odd->next = even->next;
            odd = even->next;
            even->next = odd->next;
            even = odd->next;
        }
        odd->next = head_e;
        return head;
    }
};