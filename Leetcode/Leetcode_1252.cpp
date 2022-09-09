// 奇数值单元格的数目
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int res = 0;
        vector< vector<int> > grid(n, vector<int>(m, 0));
        for(auto& indice: indices) {
            int i = indice[0], j = indice[1];
            for(int k = 0; k < m; ++k) ++grid[i][k];
            for(int k = 0; k < n; ++k) ++grid[k][j];
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) 
                if(grid[i][j] % 2 == 1) ++res;
        }
        return res;
    }
};