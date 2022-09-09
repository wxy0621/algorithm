// 链表中的节点每k个一组翻转
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if (!head) return head;
        ListNode* cur = head;
        int lengthOfListNode = 0;
        while (cur) {
            cur = cur->next;
            ++lengthOfListNode;
        }
        int numOfReverse = lengthOfListNode / k;
        ListNode* pre = nullptr;
        cur = head;
        ListNode* dumb = new ListNode(-1);
        ListNode* last = dumb;
        dumb->next = cur;
        while (numOfReverse--) {
            ListNode* temp = cur;
            for (int i = 0; i < k; ++i) {
                ListNode* nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
            }
            last->next = pre;
            last = temp;
            temp->next = cur;
            pre = nullptr;
        }
        return dumb->next;
    }
};