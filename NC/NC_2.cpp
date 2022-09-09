// 重排链表
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* pre = nullptr;
        ListNode* cur = slow->next;
        while (cur) {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        fast = head;
        slow->next = nullptr;
        slow = pre;
        bool flag = true;
        while (slow) {
            if (flag) {
                ListNode* temp = fast->next;
                fast->next = slow;
                fast = temp;
            } else {
                ListNode* temp = slow->next;
                slow->next = fast;
                slow = temp;
            }
            flag = !flag;
        }
    }
};