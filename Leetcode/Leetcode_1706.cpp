// 球会落何处
// 模拟
// 快
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return {};
        int n = grid[0].size();
        if (n == 0) return {};
        vector<int> res(n);
        for (int j = 0; j < n; ++j) {
            int col = j;
            for (auto& row: grid) {
                int last = col;
                col += row[col];
                if (col < 0 || col == n || row[col] != row[last]) {
                    col = -1;
                    break;
                }
            }
            res[j] = col;
        }
        return res;
    }
};
// 慢
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return {};
        int n = grid[0].size();
        if (n == 0) return {};
        vector<int> res(n);
        for (int j = 0; j < n; ++j) {
            int col = j;
            for (int i = 0; i < m; ++i) {
                int last = col;
                col += grid[i][col];
                if (col < 0 || col == n || grid[i][col] != grid[i][last]) {
                    col = -1;
                    break;
                }
            }
            res[j] = col;
        }
        return res;
    }
};