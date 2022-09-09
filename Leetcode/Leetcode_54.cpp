// 螺旋矩阵
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size() - 1; // 行边界，下边界
        if(m == -1) return {};
        int n = matrix[0].size() - 1; // 列边界，右边界
        int u = 0; // 行边界，上边界
        int v = 0; // 列边界，左边界
        vector<int> res;
        while(true) {
            for(int j = v; j <= n; ++j) res.emplace_back(matrix[u][j]);
            if(++u > m) break;
            for(int i = u; i <= m; ++i) res.emplace_back(matrix[i][n]);
            if(--n < v) break;
            for(int j = n; j >= v; --j) res.emplace_back(matrix[m][j]);
            if(--m < u) break;
            for(int i = m; i >= u; --i) res.emplace_back(matrix[i][v]);
            if(++v > n) break;
        }
        return res;
    }
};