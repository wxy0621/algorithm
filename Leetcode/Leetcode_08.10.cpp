// 颜色填充
// dfs
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        if (m < 1) return {};
        n = image[0].size();
        if (n < 1) return {};
        if (image[sr][sc] != newColor) dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    void dfs(vector<vector<int>>& image, int i, int j, int originColor, int newColor) {
        image[i][j] = newColor;
        if (i + 1 < m && image[i + 1][j] == originColor) {
            dfs(image, i+1, j, originColor, newColor);
        }
        if (i - 1 >= 0 && image[i - 1][j] == originColor) {
            dfs(image, i-1, j, originColor, newColor);
        }
        if (j + 1 < n && image[i][j + 1] == originColor) {
            dfs(image, i, j+1, originColor, newColor);
        }
        if (j - 1 >= 0 && image[i][j - 1] == originColor) {
            dfs(image, i, j-1, originColor, newColor);
        }
    }
private:
    int m, n;
};