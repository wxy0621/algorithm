// N皇后
// 回溯法
class Solution {
public:
    vector< vector<string> > res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> one_res(n, string(n, '.'));
        backTrace(one_res, 0);
        return res;
    }
    void backTrace(vector<string>& one_res, int row) {
        int n = one_res.size();
        if(row == n) {
            res.emplace_back(one_res);
            return;
        }
        for(int col = 0; col < n; ++col) {
            if(!isValid(one_res, row, col)) continue;
            one_res[row][col] = 'Q';
            backTrace(one_res, row + 1);
            one_res[row][col] = '.';
        }
    }
    bool isValid(vector<string>& one_res, int row, int col) {
        for(int i = 0; i < one_res.size(); ++i) {
            if(one_res[i][col] == 'Q') return false;
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if(one_res[i][j] == 'Q') return false;
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < one_res.size(); --i, ++j) {
            if(one_res[i][j] == 'Q') return false;
        }
        return true;
    }
};