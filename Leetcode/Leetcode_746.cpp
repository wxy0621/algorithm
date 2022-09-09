// 使用最小花费爬楼梯
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0 || n == 1) return 0;
        vector<int> dp(n + 1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; ++i) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        dp[n] = min(dp[n - 1], dp[n - 2]);
        return dp[n];
    }
};