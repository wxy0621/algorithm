// 交错字符串
// 动态规划
// f(i,j) 表示 s1 的前 i 个元素和 s2 的前 j 个元素是否能交错组成 s3 的前 i+j 个元素
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), t = s3.size();
        if(m + n != t) return false;
        vector< vector<int> > dp(m + 1, vector<int>(n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; ++i) {
            for(int j = 0; j <= n; ++j) {
                int p = i + j - 1;
                if(i > 0) {
                    // dp[i][j] |= (dp[i - 1][j] && (s1[i - 1] == s3[p]));
                    dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[p]));
                }
                if(j > 0) {
                    dp[i][j] |= (dp[i][j - 1] && (s2[j - 1] == s3[p]));
                }
            }
        }
        return dp[m][n];
    }
};