// 矩阵区域和
// 二维前缀和
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        if (m == 0) return {};
        int n = mat[0].size();
        if (n == 0) return {};
        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + mat[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int l1 = max(0, i - k);
                int r1 = max(0, j - k);
                int l2 = min(m - 1, i + k);
                int r2 = min(n - 1, j + k);
                res[i][j] = dp[l2 + 1][r2 + 1] + dp[l1][r1] - dp[l1][r2 + 1] - dp[l2 + 1][r1];
            }
        }
        return res;
    }
};