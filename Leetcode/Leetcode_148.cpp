// 排序链表
// 归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        ListNode* h = new ListNode(0);
        ListNode* res = h;
        while(left != nullptr && right != nullptr) {
            if(left->val > right->val) {
                h->next = right;
                right = right->next;
            } else {
                h->next = left;
                left = left->next;
            }
            h = h->next;
        }
        if(left == nullptr) {
            h->next = right;
        } else {
            h->next = left;
        }
        return res->next;
    }
};