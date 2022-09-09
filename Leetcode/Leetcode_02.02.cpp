// 返回倒数第 k 个节点
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        if(head == nullptr || k == 0) return -1;
        ListNode* slow = head, *fast = head;
        while(k--) fast = fast->next;
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;
    }
};