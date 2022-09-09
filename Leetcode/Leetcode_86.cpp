// 分隔链表
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy_big = new ListNode(0);
        ListNode* dummy_small = new ListNode(0);
        ListNode* p = head;
        ListNode* big = dummy_big;
        ListNode* small = dummy_small;
        while(p) {
            if(p->val < x) {
                small->next = p;
                small = small->next;
            } else {
                big->next = p;
                big = big->next;
            }
            p = p->next;
        }
        small->next = dummy_big->next;
        big->next = nullptr;
        return dummy_small->next;
    }
};