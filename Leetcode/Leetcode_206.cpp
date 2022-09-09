// 反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = nullptr;

        while(p1 != nullptr) {
            ListNode* p3 = p1->next;
            p1->next = p2;
            p2 = p1;
            p1 = p3;
        }
        return p2;
    }
};