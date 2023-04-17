// 所有子集
// 数学
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
    void dfs(vector<int>& nums, int cur) {
        if (nums.size() == cur) {
            res.emplace_back(vec);
            return;
        }
        vec.emplace_back(nums[cur]);
        dfs(nums, cur+1);
        vec.pop_back();
        dfs(nums, cur+1);
    }
private:
    vector<int> vec;
    vector<vector<int>> res;

};