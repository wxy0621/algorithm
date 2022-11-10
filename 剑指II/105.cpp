// 岛屿的最大面积
// dfs
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& cur) {
        if (grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        ++cur;
        if (i - 1 >= 0) dfs(grid, i - 1, j, cur);
        if (i + 1 < m) dfs(grid, i + 1, j, cur);
        if (j - 1 >= 0) dfs(grid, i, j - 1, cur);
        if (j + 1 < n) dfs(grid, i, j + 1, cur);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        if (n == 0) return 0;
        res = 0;
        int cur;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    cur = 0;
                    dfs(grid, i, j, cur);
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
private:
    int m;
    int n;
    int res;
};