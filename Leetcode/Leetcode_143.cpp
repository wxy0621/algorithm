// 重排链表
// 组合几种变换链表手段
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        // 找到链表的中间位置
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 将后半链表反转
        ListNode* pre = nullptr;
        while(slow) {
            ListNode* nex = slow->next;
            slow->next = pre;
            pre = slow;
            slow = nex;
        }
        // 重组链表
        ListNode* res = head;
        while(pre->next) {
            fast = res->next; 
            res->next = pre;
            slow = pre->next;
            pre->next = fast;
            pre = slow;
            res = fast;
        }
    }
};