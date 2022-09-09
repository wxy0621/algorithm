// 回文子串
// dp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n == 0) return 0;
        vector< vector<bool> > dp(n, vector<bool>(n));
        int res = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    ++res;
                }
            }
        }
        return res;
    }
};