// 顺时针旋转矩阵
class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        // write code here
        for (int i = 0; i < n - 1; ++i) {
            for (int j = n - 1; j > i; --j) swap(mat[i][j], mat[j][i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) swap(mat[i][j], mat[i][n-1-j]);
        }
        return mat;
    }
};