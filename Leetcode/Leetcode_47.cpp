// 全排列 II
// 回溯法
class Solution {
public:
    vector< vector<int> > res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        Backtracking(0, nums);
        return res;
    }

    void Backtracking(int start, vector<int> nums) {
        if(start == nums.size()) {
            res.emplace_back(nums);
            return;
        }
        for(int i = start; i <= nums.size() - 1; ++i) {
            // 剪枝所有不同位置相同数的交换
            if(i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            Backtracking(start + 1, nums);
        }
    }
};