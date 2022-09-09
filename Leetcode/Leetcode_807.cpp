// 保持城市天际线
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<int> horizontal(n, 0);
        vector<int> vertical(m, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                horizontal[j] = max(horizontal[j], grid[i][j]);
                vertical[i] = max(vertical[i], grid[i][j]);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res += min(horizontal[j], vertical[i]) - grid[i][j];
            }
        }
        return res;
    }
};