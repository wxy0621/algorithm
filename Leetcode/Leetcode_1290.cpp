// 二进制链表转整数
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(head == nullptr) return 0;
        ListNode* cur = head;
        int res = 0;
        while(cur != nullptr) {
            res = res * 2 + cur->val;
            cur = cur->next;
        }
        return res;
    }
};