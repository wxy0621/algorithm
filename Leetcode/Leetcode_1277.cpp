// 统计全为 1 的正方形子矩阵
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector< vector<int> > dp(m, vector<int>(n));
        return square_number = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 1) {
                    if(i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    square_number += dp[i][j];
                }
            }
        }
        return square_number;
    }
};