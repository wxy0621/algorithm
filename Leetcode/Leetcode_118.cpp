// 杨辉三角
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > res(numRows);
        if(numRows == 0) return res;
        for(int i = 0; i < numRows; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(j == 0 || j == i)
                    res[i].emplace_back(1);
                else
                    res[i].emplace_back(res[i-1][j-1] + res[i-1][j]);
            }
        }
        return res;
    }
};