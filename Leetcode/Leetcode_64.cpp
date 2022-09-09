// 最小路径和
// 滑动数组，保持更新
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(j == 0) dp[j] = grid[i][j] + dp[j];
                else dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }
        return dp[n - 1];
    }
};

// 差不多
class Solution2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        vector<int> dp(n+1, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0) dp[j+1] = dp[j] + grid[i][j];
                else if (j == 0) dp[j+1] = dp[j+1] + grid[i][j];
                else dp[j+1] = min(dp[j], dp[j+1]) + grid[i][j];
            }
        }
        return dp[n];
    }
};