// 最长公共子串
class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int n1 = str1.size(), n2 = str2.size();
        int maxLen = 0, end = 0;
        vector< vector<int> > dp(n1+1, vector<int>(n2+1, 0));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = 0;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    end = j - 1;
                }
            }
        }
        if (maxLen == 0) return "-1";
        return str2.substr(end - maxLen + 1, maxLen);
    }
};