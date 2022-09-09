// 螺旋矩阵
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        if (n == 0) return {};
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while (true) {
            for (int j = left; j <= right; ++j) res.emplace_back(matrix[top][j]);
            if (++top > bottom) break;
            for (int i = top; i <= bottom; ++i) res.emplace_back(matrix[i][right]);
            if (--right < left) break;
            for (int j = right; j >= left; --j) res.emplace_back(matrix[bottom][j]);
            if (--bottom < top) break;
            for (int i = bottom; i >= top; --i) res.emplace_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};