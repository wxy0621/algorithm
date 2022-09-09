// 最小编辑代价
// dp like Leetcode 72
class Solution {
public:
    /**
     * min edit cost
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @param ic int整型 insert cost
     * @param dc int整型 delete cost
     * @param rc int整型 replace cost
     * @return int整型
     */
    int minEditCost(string str1, string str2, int ic, int dc, int rc) {
        // write code here
        int n1 = str1.size(), n2 = str2.size();
        if (n1 == 0) return ic * n2;
        if (n2 == 0) return dc * n1;
        vector< vector<int> > dp(n1+1, vector<int>(n2+1));
        for (int i = 0; i <= n1; ++i) dp[i][0] = dc * i;
        for (int j = 0; j <= n2; ++j) dp[0][j] = ic * j;
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j] + dc, min(dp[i][j-1] + ic, dp[i-1][j-1] + rc));
            }
        }
        return dp[n1][n2];
    }
};