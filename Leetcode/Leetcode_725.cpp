// 分隔链表
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        ListNode* cur = head;
        int length = 0;
        while (cur) {
            ++length;
            cur = cur->next;
        }
        int first = 0, second = 0;
        int small = length / k;
        if (length % k == 0) {
            second = k;
        } else {
            first = length - length / k * k;
            second = k - first;
        }
        cur = head;
        for (int i = 0; i < first; ++i) {
            res.emplace_back(cur);
            for (int j = 0; j < small; ++j) {
                cur = cur->next;
            }
            ListNode* nex = cur->next;
            cur->next = nullptr;
            cur = nex;
        }
        for (int i = 0; i < second; ++i) {
            if (!cur) {
                res.emplace_back(nullptr);
                continue;
            }
            res.emplace_back(cur);
            for (int j = 0; j < small - 1; ++j) {
                cur = cur->next;
            }
            ListNode* nex = cur->next;
            cur->next = nullptr;
            cur = nex;
        }
        return res;
    }
};