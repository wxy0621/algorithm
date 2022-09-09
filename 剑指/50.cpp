// 第一个只出现一次的字符
class Solution {
public:
    char firstUniqChar(string s) {
        if(s == "") return ' ';
        unordered_map<char, int> m;
        for(auto& c: s) ++m[c];
        for(auto& c: s) {
            if(m[c] == 1) return c;
        }
        return ' ';
    }
};