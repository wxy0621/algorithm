// 分割平衡字符串
class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int count_R = 0, count_L = 0;
        for(auto& c: s) {
            if(c == 'R') ++count_R;
            if(c == 'L') ++count_L;
            if(count_R != 0 && count_L == count_R) {
                ++res;
                count_R = 0;
                count_L = 0;
            }
        }
        return res;
    }
};