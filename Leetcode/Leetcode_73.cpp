// 矩阵置零
// 原地变化，常数空间
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        bool row0_flag = false;
        bool col0_flag = false;
        
        for(int i = 0; i < m; ++i) {
            if(matrix[i][0] == 0) {
                row0_flag = true;
                break;
            }
        }

        for(int j = 0; j < n; ++j) {
            if(matrix[0][j] == 0) {
                col0_flag = true;
                break;
            }
        }

        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(row0_flag) {
            for(int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        if(col0_flag) {
            for(int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};

// O(m + n) 空间复杂度
class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};