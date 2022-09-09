// 删除排序链表中的重复元素
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* p = head;
        while(p && p->next) {
            if(p->val == p->next->val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return head;
    }
};

// 内部也循环
class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* cur = head;
        while (cur && cur->next) {
            while (cur->next && cur->val == cur->next->val) cur->next = cur->next->next;
            cur = cur->next;
        }
        return head;
    }
};