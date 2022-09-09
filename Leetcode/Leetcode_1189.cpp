// “气球”的最大数量
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int res = INT_MAX;
        int count[5] = {0};
        for(auto& c: text) {
            if(c == 'a') ++count[0];
            if(c == 'b') ++count[1];
            if(c == 'l') ++count[2];
            if(c == 'n') ++count[3];
            if(c == 'o') ++count[4];
        }
        for(int i = 0; i < 5; ++i) {
            if(i == 2 || i == 4) res = min(res, count[i] / 2);
            else res = min(res, count[i]);
        }
        return res;
    }
};