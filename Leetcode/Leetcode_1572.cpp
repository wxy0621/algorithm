// 矩阵对角线元素的和
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0, n = mat.size();
        for(int i = 0; i < n; ++i) {
            res += mat[i][i];
            res += mat[i][n-1-i];
        }
        return n % 2 ? (res - mat[n / 2][n / 2]) : res;
    }
};