// 距离顺序排列矩阵单元格
// 桶排序
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector< vector<int> > res(R * C, vector<int>(2, 0));
        vector< vector<int> > m(R + C - 1);
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                int dis = abs(r0 - i) + abs(c0 - j);
                m[dis].emplace_back(i);
                m[dis].emplace_back(j);
            }
        }
        int count = 0;
        for(int i = 0; i < R + C - 1; ++i) {
            for(int j = 0; j < m[i].size(); j += 2) {
                res[count][0] = m[i][j];
                res[count][1] = m[i][j + 1];
                ++count;
            }
        }
        return res;
    }
};