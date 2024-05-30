// 矩阵中的局部最大值
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n < 3)  return {};
        vector<vector<int>> res(n - 2, vector<int>(n - 2, 0));
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                for (int p = i; p < 3 + i; ++p) {
                    for (int q = j; q < 3 + j; ++q) {
                        res[i][j] = max(res[i][j], grid[p][q]);
                    }
                }
            }
        }
        return res;
    }
};