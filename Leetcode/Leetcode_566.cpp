// 重塑矩阵
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if(m * n != r * c) return nums;
        vector<vector<int>> res(r, vector<int>(c, 0));
        int u = 0, v = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                res[u][v++] = nums[i][j];
                if(v == c) {
                    ++u;
                    v = 0;
                }
            }
        }
        return res;
    }
};