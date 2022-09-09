// 硬币
// dp
class Solution {
public:
    int waysToChange(int n) {
        vector<int> dp(n + 1, 0);
        vector<int> coins = {1, 5, 10, 25};
        dp[0] = 1;
        for (int j = 0; j < 4; ++j) {
            for (int i = coins[j]; i <= n; ++i) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % 1000000007;
            }
        }
        return dp[n];
    }
};