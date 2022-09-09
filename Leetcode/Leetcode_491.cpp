// 递增子序列
// 回溯法
class Solution {
public:
    set<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> tmp;
        dfs(nums, 0, tmp);
        return vector< vector<int> >(res.begin(), res.end());
    }
    void dfs(vector<int>& nums, int i, vector<int>& tmp) {
        if(tmp.size() >=2) res.insert(tmp);
        for(int j = i; j < nums.size(); ++j) {
            if(!tmp.empty() && tmp.back() > nums[j]) continue;
            tmp.emplace_back(nums[j]);
            dfs(nums, j + 1, tmp);
            tmp.pop_back();
        }
    }
};