// 重排链表
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* cur = slow->next;
        ListNode* pre = nullptr;
        while (cur) {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        fast = pre;
        slow->next = nullptr;
        slow = head;
        bool flag = true;
        while (fast) {
            if (flag) {
                ListNode* nex = slow->next;
                slow->next = fast;
                slow = nex;
            } else {
                ListNode* nex = fast->next;
                fast->next = slow;
                fast = nex;
            }
            flag = !flag;
        }
    }
};