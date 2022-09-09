// 最长公共子序列
// dp[i][j] 表示前 text1的前 i，text2的前 j 个位置的最长公共子序列的长度
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector< vector<int> > dp(n1 + 1, vector<int>(n2 + 1, 0));
        for(int i = 1; i <= n1; ++i) {
            for(int j = 1; j <= n2; ++j) {
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n1][n2];
    }
};