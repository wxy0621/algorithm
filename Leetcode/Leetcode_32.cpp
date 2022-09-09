// 最长有效括号
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int res = 0;
        vector<int> dp(n, 0);
        for(int i = 1; i < n; ++i) {
            if(s[i] == ')') {
                if(s[i-1] == '(')
                    dp[i] = (i-2 >= 0 ? dp[i-2] : 0) + 2;
                // 潜在含义：s[i-1] == ')'，往前移动 dp[i-1]+1 个位置，判断是否可以组成（）对
                else if(i-1-dp[i-1]>=0 && s[i-1-dp[i-1]] == '(')
                    dp[i] = dp[i-1] + (i-2-dp[i-1]>=0 ? dp[i-2-dp[i-1]] : 0) + 2;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};