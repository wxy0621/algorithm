// 删除有序链表中重复出现的元素
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if (!head) return nullptr;
        ListNode* res = new ListNode(-1);
        ListNode* pre = res;
        pre->next = head;
        ListNode* start = res->next;
        ListNode* end = start->next;
        bool onceFlag = true;
        while (start) {
            while (end && start->val == end->val) {
                end = end->next;
                onceFlag = false;
            }
            if (!onceFlag) {
                pre->next = end;
            } else {
                pre = start;
            }
            if (!end) break;
            start = end;
            end = end->next;
            onceFlag = true;
        }
        return res->next;
    }
};