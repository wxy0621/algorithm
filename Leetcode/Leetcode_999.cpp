// 可以被一步捕获的棋子数
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int count = 0;
        int start_x, start_y = 0;
        int walk_x[4] = {1, -1, 0, 0};
        int walk_y[4] = {0, 0, 1, -1};
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                if(board[i][j] == 'R') {
                    start_x = i;
                    start_y = j;
                }
            }
        }

        for(int i = 0; i < 4; ++i) {
            for(int step = 0;; ++step) {
                int temp_x = start_x + step * walk_x[i];
                int temp_y = start_y + step * walk_y[i];
                if(temp_x < 0 || temp_x >= 8 || temp_y < 0 || temp_y >= 8 || board[temp_x][temp_y] == 'B')
                break;
                if(board[temp_x][temp_y] == 'p') {
                    ++count;
                    break;
                }
            }
        }
        return count;
    }
};