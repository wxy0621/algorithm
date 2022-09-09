// 最大的以 1 为边界的正方形
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        int max_len = 0;
        vector< vector< vector<int> > > dp(m + 1, vector< vector<int> >(n + 1, vector<int>(2, 0)));
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(grid[i - 1][j - 1] == 1) {
                    dp[i][j][0] += dp[i][j - 1][0] + 1; // 由行产生
                    dp[i][j][1] += dp[i - 1][j][1] + 1; // 由列产生
                    int len = min(dp[i][j][0], dp[i][j][1]);
                    // 排除 [[0,1],[1,1]] 这种情况
                    // 判断这个可能的正方形右上角左侧是否有连续 len 个1 && 左下角的上方是否有连续 len 个1
                    while(len > 0) {
                        if(dp[i - len + 1][j][0] >= len && dp[i][j - len + 1][1] >= len)
                            break;
                        --len;
                    }
                    max_len = max(max_len, len);
                }
            }
        }
        return max_len * max_len;
    }
};