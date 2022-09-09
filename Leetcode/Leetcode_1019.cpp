// 链表中的下一个更大节点
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        stack<int> tmp;
        for (auto i = head; i != nullptr; i = i->next)
            nums.emplace_back(i->val);
        int n = nums.size();
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            while (!tmp.empty() && tmp.top() <= nums[i])
                tmp.pop();
            res[i] = tmp.empty() ? 0 : tmp.top();
            tmp.push(nums[i]);
        }
        return res;
    }
};