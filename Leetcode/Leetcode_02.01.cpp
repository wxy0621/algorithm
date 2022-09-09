// 移除重复节点
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head == nullptr)
            return head;
        unordered_set<int> temp = {head->val};
        ListNode* p = head;
        while(p->next != nullptr) {
            ListNode* q = p->next;
            if(!temp.count(q->val)) {
                temp.insert(q->val);
                p = p->next;
            } else {
                p->next = p->next->next;
            }
        }
        return head;
    }
};