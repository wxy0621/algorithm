#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 && j == 0)
                    continue;
                else if(i == 0)
                    grid[i][j] += grid[i][j-1];
                else if(j == 0)
                    grid[i][j] += grid[i-1][j];
                else
                    grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};

// 滑动更新，效率更高
class Solution2 {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> res(n+1, 0);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                res[j+1] = max(res[j], res[j+1]) + grid[i][j];
            }
        }
        return res[n];
    }
};

int main() {

    return 0;
}