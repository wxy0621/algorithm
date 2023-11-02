// 找出分区值
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for (int i = 1; i < n; ++i) {
            res = min(nums[i] - nums[i-1], res);
        }
        return res;
    }
};