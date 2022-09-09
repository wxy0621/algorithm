// 将一维数组转变成二维数组
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();
        if (len != m * n) return {};
        vector< vector<int> > res;
        int k = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> layer(n);
            for (int j = 0; j < n; ++j) {
                layer[j] = original[k++];
            }
            res.emplace_back(layer);
        }
        return res;
    }
};