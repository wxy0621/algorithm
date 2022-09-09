// 最佳买卖股票时机含冷冻期
// 三状态的动态规划，画状态转移图
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        int dp[n][3];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for(int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i]);
            dp[i][2] = dp[i - 1][0];
        }
        return max(dp[n - 1][0], dp[n - 1][2]);
    }
};

// 优化
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        int a = 0;
        int b = -prices[0];
        int c = 0;
        int temp;
        for(int i = 1; i < n; ++i) {
            temp = a;
            a = max(a, b + prices[i]);
            b = max(b, c - prices[i]);
            c = temp;
        }
        return max(a, c);
    }
};