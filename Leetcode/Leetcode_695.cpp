// 岛屿的最大面积
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }

    int dfs(vector< vector<int> >& grid, int i, int j) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        int temp_i[4] = {1, -1, 0, 0};
        int temp_j[4] = {0, 0, -1, 1};
        int res = 1;
        for(int k = 0; k < 4; ++k) {
            res += dfs(grid, i + temp_i[k], j + temp_j[k]);
        }
        return res;
    }
};

int main()
{
    
    return 0;
}