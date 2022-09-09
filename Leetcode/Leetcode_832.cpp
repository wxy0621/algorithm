// 翻转图像
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        if(m == 0) return {};
        int n = A[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n / 2; ++j) {
                swap(A[i][j], A[i][n - 1 - j]);
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                A[i][j] = abs(A[i][j] - 1);
            }
        }
        return A;
    }
};

// 改版
class Solution2 {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        if(m == 0) return {};
        int n = A[0].size();
        for(int i = 0; i < m; ++i) reverse(A[i].begin(), A[i].end());
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) A[i][j] ^= 1;
        }
        return A;
    }
};