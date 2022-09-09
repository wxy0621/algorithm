// 粉刷房子
// dp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(3));
        for (int j = 0; j < 3; ++j) dp[0][j] = costs[0][j];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
        }
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};
// Optimize memory
class Solution2 {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        vector<int> dp(3);
        for (int j = 0; j < 3; ++j) dp[j] = costs[0][j];
        for (int i = 1; i < n; ++i) {
            vector<int> temp(3);
            temp[0] = min(dp[1], dp[2]) + costs[i][0];
            temp[1] = min(dp[0], dp[2]) + costs[i][1];
            temp[2] = min(dp[0], dp[1]) + costs[i][2];
            dp = temp;
        }
        return min(dp[0], min(dp[1], dp[2]));
    }
};