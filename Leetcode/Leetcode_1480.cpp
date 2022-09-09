// 一维数组的动态和
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; ++i) {
            dp[i] = nums[i] + dp[i - 1];
        }
        return dp;
    }
};