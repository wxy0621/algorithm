// 有效的数独
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int grid[9][9] = {0};
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') continue;
                int current_number = board[i][j] - '1';
                if(row[i][current_number]) return false;
                if(col[j][current_number]) return false;
                if(grid[(i / 3) * 3 + j / 3][current_number]) return false;
                row[i][current_number] = 1;
                col[j][current_number] = 1;
                grid[(i / 3) * 3 + j / 3][current_number] = 1;
            }
        }
        return true;
    }
};