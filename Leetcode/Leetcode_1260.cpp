// 二维网格迁移
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        if(m == 0) return { };
        int n = grid[0].size();
        vector< vector<int> > res(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int p = (i * n + j + k) / n % m;
                int q = (i * n + j + k) % n;
                res[p][q] = grid[i][j];
            }
        }
        return res;
    }
};