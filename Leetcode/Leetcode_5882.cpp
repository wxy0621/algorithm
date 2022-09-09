// 网格游戏
// 前缀和，not dfs
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long left = 0, right = 0;
        for (int i = 1; i < n; ++i) right += grid[0][i];
        long long res = right;
        for (int i = 1; i < n; ++i) {
            left += grid[1][i - 1];
            right -= grid[0][i];
            res = min(res, max(left, right));
        }
        return res;
    }
};