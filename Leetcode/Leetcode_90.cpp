// 子集 II
// 回溯法
class Solution {
public:
    vector< vector<int> > res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        Backtracking(nums, temp, 0);
        return res;
    }

    void Backtracking(vector<int>& nums, vector<int> temp, int k) {
        res.emplace_back(temp);
        for(int i = k; i < nums.size(); ++i) {
            // 剪枝掉的是同一层的，因为同一层的子集长度一致，才会出现重复的
            // 例如本来[1,2,3] -> [1,2,2]，本来该层会出现[1,2]和[1,3]两个答案，但是现在变成了两个[1,2]，因此剪枝掉后面那个[1,2]
            if(i > k && nums[i] == nums[i - 1]) continue;
            temp.emplace_back(nums[i]);
            Backtracking(nums, temp, i + 1);
            temp.pop_back();
        }
    }
};