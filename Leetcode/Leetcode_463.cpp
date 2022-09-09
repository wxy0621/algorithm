// 岛屿的周长
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int move_x[4] = {1, -1, 0, 0};
        int move_y[4] = {0, 0, 1, -1};
        int res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    for(int k = 0; k < 4; ++k) {
                        int temp_x = i + move_x[k];
                        int temp_y = j + move_y[k];
                        if(temp_x < 0 || temp_x >= m || temp_y < 0 || temp_y >= n || grid[temp_x][temp_y] == 0)
                            ++res;
                    }
                }
            }
        }
        return res;
    }
};