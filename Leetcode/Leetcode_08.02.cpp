// 迷路的机器人
// dfs
class Solution {
public:
    void dfs(vector<vector<int>>& obstacleGrid, vector<vector<bool>>& visited, int i, int j) {
        if (obstacleGrid[i][j] == 1 || visited[i][j]) return;
        visited[i][j] = true;
        res.emplace_back(vector{i, j});
        if (i == m - 1 && j == n - 1) isEnd = true;
        if (i < m - 1) dfs(obstacleGrid, visited, i + 1, j);
        if (isEnd) return;
        if (j < n - 1) dfs(obstacleGrid, visited, i, j + 1);
        if (isEnd) return;
        res.pop_back();
    }
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        if (m == 0) return {};
        n = obstacleGrid[0].size();
        if (n == 0) return {};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        isEnd = false;
        dfs(obstacleGrid, visited, 0, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    int m;
    int n;
    int isEnd;
};