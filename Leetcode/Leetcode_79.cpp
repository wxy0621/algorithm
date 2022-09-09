// 单词搜索
// 回溯法
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(helper(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }

    // & 很重要，不然内存消耗严重
    bool helper(vector< vector<char> >& board, string& word, int index, int i, int j) {
        if(board[i][j] != word[index]) return false;
        if(index == word.size() - 1) return true;

        char temp = board[i][j];
        board[i][j] = '0';
        ++index;
        if((i < board.size() - 1 && (helper(board, word, index, i + 1, j))) || (j < board[0].size() - 1 && (helper(board, word, index, i, j + 1))) || (i > 0 && (helper(board, word, index, i - 1, j))) || (j > 0 && (helper(board, word, index, i, j - 1))))
            return true;
        board[i][j] = temp;
        return false;
    }
};