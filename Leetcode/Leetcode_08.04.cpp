// 幂集
class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int> >& res, int start, const int& n, vector<int> temp) {
        res.emplace_back(temp);
        for (int i = start; i < n; ++i) {
            temp.emplace_back(nums[i]);
            helper(nums, res, i+1, n, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<vector<int> > res;
        vector<int> temp;
        helper(nums, res, 0, n, temp);
        return res;
    }
};