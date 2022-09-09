// 子集
// 回溯法
class Solution {
public:
    vector< vector<int> > res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        Backtracking(nums, temp, 0);
        return res;
    }

    void Backtracking(vector<int>& nums, vector<int> temp, int k) {
        res.emplace_back(temp);
        for(int i = k; i < nums.size(); ++i) {
            temp.emplace_back(nums[i]);
            Backtracking(nums, temp, i + 1);
            temp.pop_back();
        }
    }
};