// 矩阵中的路径
// 回溯法
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if(m * n < word.size()) return false;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(helper(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }

    bool helper(vector< vector<char> >& board, string& word, int index, int i, int j) {
        if(board[i][j] != word[index]) return false;
        if(index == word.size() - 1) return true;

        char temp = board[i][j];
        board[i][j] = '0';
        ++index;
        if(i > 0 && helper(board, word, index, i - 1, j)) return true;
        if(j > 0 && helper(board, word, index, i, j - 1)) return true;
        if(i < board.size() - 1 && helper(board, word, index, i + 1, j)) return true;
        if(j < board[0].size() - 1 && helper(board, word, index, i, j + 1)) return true;
        board[i][j] = temp;

        return false;
    }
};