// 如果相邻两个颜色均相同则删除当前颜色
class Solution {
public:
    bool winnerOfGame(string colors) {
        int resA = 0, resB = 0;
        int n = colors.size();
        int lastChar = colors[0];
        int countChar = 1;
        for (int i = 1; i < n; ++i) {
            if (lastChar == colors[i]) {
                if (++countChar >= 3) {
                    if (colors[i] == 'A') ++resA;
                    else ++resB;
                }
            } else {
                countChar = 1;
                lastChar = colors[i];
            }
        }
        return resA > resB;
    }
};