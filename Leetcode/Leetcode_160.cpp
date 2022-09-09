// 相交链表
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while(a != b) {
            if(a == nullptr) a = headB;
            else a = a->next;
            if(b == nullptr) b = headA;
            else b = b->next;
        }
        return a;
    }
};