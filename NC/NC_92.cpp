// 最长公共子序列
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        // write code here
        int len_s1 = s1.size(), len_s2 = s2.size();
        vector< vector<int> > dp(len_s1 + 1, vector<int>(len_s2 + 1, 0));
        for (int i = 1; i <= len_s1; ++i) {
            for (int j = 1; j <= len_s2; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        if (dp[len_s1][len_s2] == 0) return "-1";
        int i = len_s1, j = len_s2;
        string res = "";
        while (i != 0 && j != 0) {
            if (s1[i-1] == s2[j-1]) {
                res += s1[i-1];
                --i;
                --j;
            } else {
                if (dp[i-1][j] > dp[i][j-1]) --i;
                else --j;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};