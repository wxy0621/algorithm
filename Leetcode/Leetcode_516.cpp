// 最长回文子序列
// dp
// 反向
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n < 2) return n;
        vector< vector<int> > dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            char leftChar = s[i];
            for (int j = i + 1; j < n; ++j) {
                char rightChar = s[j];
                if (leftChar == rightChar) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};

// 正向
class Solution2 {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n < 2) return n;
        vector< vector<int> > dp(n, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            dp[j][j] = 1;
            char leftChar = s[j];
            for (int i = j - 1; i >= 0; --i) {
                char rightChar = s[i];
                if (leftChar == rightChar) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};