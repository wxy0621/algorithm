// 完全平方数
class Solution {
public:
    int numSquares(int n) {
        if (n == 0) return 0;
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; ++i) {
            dp[i] = i;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= sqrt(i); ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};