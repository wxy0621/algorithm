// 删除并获得点数
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int count[10001] = {0};
        for (auto& num: nums) ++count[num];
        int dp[10001] = {0};
        dp[1] = 1 * count[1];
        for (int i = 2; i < 10001; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + i * count[i]);
        }
        return dp[10000];
    }
};