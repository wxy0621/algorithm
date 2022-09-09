// 上升下降字符串
class Solution {
public:
    string res;
    string sortString(string s) {
        int count[26] = {0};
        for(auto& ch: s) ++count[ch - 97];
        while(true) {
            if(!haveStr(count)) break;
            for(int i = 0; i < 26; ++i) appendStr(count, i);
            for(int i = 0; i < 26; ++i) appendStr(count, 25 - i);
        }
        return res;
    }
    bool haveStr(int count[26]) {
        for(int i = 0; i < 26; ++i) {
            if(count[i] > 0) return true;
        }
        return false;
    }
    void appendStr(int count[26], int i) {
        if(count[i]) {
            --count[i];
            res += (i + 97);
        }
    }
};