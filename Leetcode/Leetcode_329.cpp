// 矩阵中的最长递增路径
// 纯回溯法，但超时
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        int max_len = 0, cur_len = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                Backtracking(matrix, i, j, INT_MIN, cur_len, max_len);
            }
        }
        return max_len;
    }

    void Backtracking(vector<vector<int>>& matrix, int i, int j, int last_num, int cur_len, int& max_len) {
        if(matrix[i][j] <= last_num) return;
        ++cur_len;
        if(i + 1 < matrix.size()) {
            Backtracking(matrix, i + 1, j, matrix[i][j], cur_len, max_len);
            max_len = max(max_len, cur_len);
        }
        if(i - 1 >= 0) {
            Backtracking(matrix, i - 1, j, matrix[i][j], cur_len, max_len);
            max_len = max(max_len, cur_len);
        }
        if(j + 1 < matrix[0].size()) {
            Backtracking(matrix, i, j + 1, matrix[i][j], cur_len, max_len);
            max_len = max(max_len, cur_len);
        }
        if(j - 1 >= 0) {
            Backtracking(matrix, i, j - 1, matrix[i][j], cur_len, max_len);
            max_len = max(max_len, cur_len);
        }
        --cur_len;
    }
};

