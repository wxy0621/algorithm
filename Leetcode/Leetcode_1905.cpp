// 统计子岛屿
// DFS
class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) {
            return;
        }
        if (grid1[i][j] != 1) {
            flag = false;
        }
        grid2[i][j] = 0;
        dfs(grid1, grid2, i - 1, j);
        dfs(grid1, grid2, i + 1, j);
        dfs(grid1, grid2, i, j - 1);
        dfs(grid1, grid2, i, j + 1);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        if (m == 0) return 0;
        n = grid1[0].size();
        if (n == 0) return 0;
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    flag = true;
                    dfs(grid1, grid2, i, j);
                    if (flag) ++res;
                }
            }
        }
        return res;
    }
private:
    int m;
    int n;
    bool flag;
};