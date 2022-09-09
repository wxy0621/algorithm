// 回文排列
class Solution {
public:
    bool canPermutePalindrome(string s) {
        bool flag = true;
        unordered_map<char, int> m;
        for(auto& c: s) ++m[c];
        for(auto& t: m) {
            if(t.second % 2 != 0 && !flag) return false;
            if(t.second % 2 != 0) flag = false;
        }
        return true;
    }
};