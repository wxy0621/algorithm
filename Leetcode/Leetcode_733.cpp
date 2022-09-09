// 图像渲染
// dfs
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        if(m == 0) return { };
        int n = image[0].size();
        vector<vector<int>> res = image;
        int initColor = image[sr][sc];
        if(initColor != newColor) helper(res, sr, sc, newColor, initColor, m, n);

        return res;
    }
    void helper(vector< vector<int> >& res, int i, int j, const int& newColor, const int& initColor, const int& m, const int& n) {
        if(res[i][j] != initColor) return;
        res[i][j] = newColor;
        if(i + 1 < m) helper(res, i + 1, j, newColor, initColor, m, n);
        if(i - 1 >= 0) helper(res, i - 1, j, newColor, initColor, m, n);
        if(j + 1 < n) helper(res, i, j + 1, newColor, initColor, m, n);
        if(j - 1 >= 0) helper(res, i, j - 1, newColor, initColor, m, n);
    }
};