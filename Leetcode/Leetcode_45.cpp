// 跳跃游戏 II
// 贪心
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0, end = 0, max_pos = 0;
        for(int i = 0; i < n - 1; ++i) {
            max_pos = max(max_pos, i + nums[i]);
            if(i == end) {
                end = max_pos;
                ++count;
            }
        }
        return count;
    }
};

// dp
class Solution2 {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                if (i + j >= n) break;
                dp[i+j] = min(dp[i] + 1, dp[i+j]);
            }
        }
        return dp[n-1];
    }
};