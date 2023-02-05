// 统计字典序元音字符串的数目
// dp
class Solution {
public:
    int countVowelStrings(int n) {
        if (n == 0) return 0;
        vector<int> dp(5, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < 5; ++j) {
                dp[j] = dp[j-1] + dp[j];
            }
        }
        int res = dp[0] + dp[1] + dp[2] + dp[3] + dp[4];
        return res;
    }
};