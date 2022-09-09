// 连续数列
// dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n);
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(dp[i], res);
        }
        return res;
    }
};

// 不用dp
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int temp_max = nums[0];
        int res = nums[0];
        for(int i = 1; i < n; ++i) {
            temp_max = max(temp_max, 0) + nums[i];
            res = max(temp_max, res);
        }
        return res;
    }
};