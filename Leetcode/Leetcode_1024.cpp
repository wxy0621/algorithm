// 视频拼接
// 动态规划
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T + 1, INT_MAX - 1);
        dp[0] = 0;
        for(int i = 1; i <= T; ++i) {
            for(auto& temp: clips) {
                if(i > temp[0] && i <= temp[1]) {
                    dp[i] = min(dp[i], dp[temp[0]] + 1);
                }
            }
        }
        return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }
};