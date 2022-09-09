// 数组中最大数对和的最小值
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());
        int res = INT_MIN;
        for (int i = 0; i < n / 2; ++i) res = max(res, nums[i] + nums[n-i-1]);
        return res;
    }
};
