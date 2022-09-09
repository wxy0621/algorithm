// 重新排列数组
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int i = 0, j = nums.size() / 2;
        while(j < nums.size()) {
            res.emplace_back(nums[i++]);
            res.emplace_back(nums[j++]);
        }
        return res;
    }
};