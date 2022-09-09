// 判定是否互为字符重排
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        unordered_map<char, int> m;
        for(auto& c: s1) ++m[c];
        for(auto& c: s2) --m[c];
        for(auto& t: m) {
            if(t.second != 0) return false;
        }
        return true;
    }
};