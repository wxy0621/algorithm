// 飞地的数量
// DFS 从外圈进行 DFS 遍历，未访问的格子即是飞地
class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        if (grid[i][j] == 0 || visited[i][j]) return;
        visited[i][j] = true;
        if (i - 1 > 0) dfs(i - 1, j, visited, grid);
        if (i + 1 < m) dfs(i + 1, j, visited, grid);
        if (j - 1 > 0) dfs(i, j - 1, visited, grid);
        if (j + 1 < n) dfs(i, j + 1, visited, grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        if (n == 0) return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(i, 0, visited, grid);
            dfs(i, n - 1, visited, grid);
        }
        for (int j = 1; j < n - 1; ++j) {
            dfs(0, j, visited, grid);
            dfs(m - 1, j, visited, grid);
        }
        int res = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (!visited[i][j] && grid[i][j] == 1) ++res;
            }
        }
        return res;
    }
private:
    int m;
    int n;
};