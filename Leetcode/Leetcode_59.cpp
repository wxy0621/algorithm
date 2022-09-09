// 螺旋矩阵 II
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector< vector<int> > res(n, vector<int>(n, 0));
        int col1 = 0, col2 = n - 1, row1 = 0, row2 = n - 1;
        int count = 1;
        while (count <= n*n) {
            for (int j = col1; j <= col2; ++j) {
                res[row1][j] = count;
                ++count;
            }
            ++row1;
            for (int i = row1; i <= row2; ++i) {
                res[i][col2] = count;
                ++count;
            }
            --col2;
            for (int j = col2; j >= col1; --j) {
                res[row2][j] = count;
                ++count;
            }
            --row2;
            for (int i = row2; i >= row1; --i) {
                res[i][col1] = count;
                ++count;
            }
            ++col1;
        }
        return res;
    }
};