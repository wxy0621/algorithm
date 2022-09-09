// 回文链表
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        vector<int> res;
        while(head) {
            res.emplace_back(head->val);
            head = head->next;
        }
        vector<int> rev = res;
        reverse(rev.begin(), rev.end());
        return res == rev;
    }
};