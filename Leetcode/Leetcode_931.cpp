// 下降路径最小和
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        if (n == 1) return matrix[0][0];
        int res = INT_MAX;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    matrix[i][j] += min(matrix[i+1][j], matrix[i+1][j+1]);
                } else if (j == n - 1) {
                    matrix[i][j] += min(matrix[i+1][j], matrix[i+1][j-1]);
                } else {
                    matrix[i][j] += min(min(matrix[i+1][j], matrix[i+1][j-1]), matrix[i+1][j+1]);
                }
                if (i == 0) {
                    res = min(res, matrix[i][j]);
                }
            }
        }
        return res;
    }
};