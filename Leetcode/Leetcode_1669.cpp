// 合并两个链表
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *dumb = new ListNode(-1);
        ListNode *cur = dumb;
        cur->next = list1;
        for (int i = 0; i < a; ++i) cur = cur->next;
        ListNode *above = cur->next;
        cur->next = list2;
        while (cur->next) cur = cur->next;
        for (int i = a; i < b; ++i) above = above->next;
        cur->next = above->next;
        return dumb->next;
    }
};