// 图片平滑器

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        if(m == 0) return {};
        int n = M[0].size();
        vector< vector<int> > res(m, vector<int>(n, 0));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int count = 0;
                for(int p = i - 1; p <= i + 1; ++p) {
                    for(int q = j - 1; q <= j + 1; ++q) {
                        if(p >= 0 && p < m && q >= 0 && q < n) {
                            res[i][j] += M[p][q];
                            ++count;
                        }
                    }
                }
                res[i][j] /= count;
            }
        }
        return res;
    }
};