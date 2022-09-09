// 链表相交
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1 != t2) {
            if(!t1) t1 = headB;
            else t1 = t1->next;
            if(!t2) t2 = headA;
            else t2 = t2->next;
        }
        return t1;
    }
};