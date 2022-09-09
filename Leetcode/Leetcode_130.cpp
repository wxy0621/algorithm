// 被围绕的区域
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'O') {
            return;
        }
        board[i][j] = '#';
        if (i - 1 >= 0) dfs(board, i - 1, j);
        if (i + 1 < m) dfs(board, i + 1, j);
        if (j - 1 >= 0) dfs(board, i, j - 1);
        if (j + 1 < n) dfs(board, i, j + 1);
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        if (n == 0) return;
        for (int i = 0; i < m; ++i) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int j = 1; j < n - 1; ++j) {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
private:
    int m;
    int n;
};