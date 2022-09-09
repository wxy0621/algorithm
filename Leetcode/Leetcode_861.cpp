// 翻转矩阵后的得分
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        int res = pow(2, n - 1) * m;
        for (int i = 0; i < m; ++i) {
            if (A[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    A[i][j] ^= 1;
                }
            }
        }
        for (int j = 1; j < n; ++j) {
            int count = 0;
            for (int i = 0; i < m; ++i) {
                if (A[i][j] == 0) ++count;
            }
            count = (m - count) > count ? (m - count) : count;
            res += pow(2, n - 1 - j) * count;
        }
        return res;
    }
};