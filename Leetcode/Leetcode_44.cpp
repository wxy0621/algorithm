// 通配符匹配
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector< vector<bool> > dp(n+1, vector<bool>(m+1));
        dp[0][0] = true;
        for(int i = 1; i <= n; ++i) {
            if(p[i-1] != '*')
                break;
            dp[i][0] = true;
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(p[i-1] == s[j-1] || p[i-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*')
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};