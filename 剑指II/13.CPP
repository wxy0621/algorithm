// 二维子矩阵的和
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        matrix_sum.resize(m+1, vector<int>(n+1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix_sum[i+1][j+1] = matrix_sum[i+1][j] + matrix[i][j] + matrix_sum[i][j+1] - matrix_sum[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return matrix_sum[row2+1][col2+1] + matrix_sum[row1][col1]
         - matrix_sum[row1][col2+1] - matrix_sum[row2+1][col1];
    }
private:
    vector<vector<int>> matrix_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */