// 排序矩阵查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (target == matrix[i][j]) return true;
            else if (target > matrix[i][j]) ++i;
            else --j;
        }
        return false;
    }
};