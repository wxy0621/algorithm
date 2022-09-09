// 删除有序链表中的重复元素
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if (!head || !head->next) return head;
        ListNode* cur = head;
        while (cur && cur->next) {
            while (cur->next && cur->val == cur->next->val) {
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return head;
    }
};