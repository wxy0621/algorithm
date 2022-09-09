// 链表内指定区间反转
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        if (!head) return head;
        ListNode* cur;
        ListNode* pre = new ListNode(-1);
        ListNode* dumb = pre;
        pre->next = head;
        int dif = n - m + 1;
        while (--m) pre = pre->next;
        cur = pre->next;
        ListNode* left = pre;
        ListNode* start = cur;
        while (dif--) {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        ListNode* end = pre;
        ListNode* right = cur;
        start->next = right;
        left->next = end;
        return dumb->next;
    }
};