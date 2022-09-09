// 解码字母到整数映射
class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if(i + 2 < n && s[i + 2] == '#') {
                res += ((s[i] - '0') * 10 + s[i + 1] - '1' + 'a');
                i += 2;
            } else
                res += (s[i] - '1' + 'a');
        }
        return res;
    }
};