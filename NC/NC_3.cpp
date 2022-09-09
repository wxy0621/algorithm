// 链表中环的入口结点
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (!pHead) return pHead;
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        if (!fast || !fast->next) return nullptr;
        fast = pHead;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};