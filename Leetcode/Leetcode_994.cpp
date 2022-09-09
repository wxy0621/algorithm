// 腐烂的橘子
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min = 0, fresh = 0;
        queue< pair<int, int> > q;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) ++fresh;
            }
        }
        vector< pair<int, int> > move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()) {
            bool rotten = false;
            int n = q.size();
            for(int k = 0; k < n; ++k) {
                auto x = q.front();
                q.pop();
                for(auto cur: move) {
                    int i = x.first + cur.first;
                    int j = x.second + cur.second;
                    if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        q.push({i, j});
                        --fresh;
                        rotten = true;
                    }
                }
            }
            if(rotten) ++min;
        }
        return fresh ? -1 : min;
    }
};