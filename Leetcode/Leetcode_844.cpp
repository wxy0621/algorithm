// 比较含退格的字符串
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> S_after;
        vector<char> T_after;
        for(auto& c: S) {
            if(c == '#') {
                if(!S_after.empty())
                    S_after.pop_back();
            } else {
                S_after.emplace_back(c);
            }
        }
        for(auto& c: T) {
            if(c == '#') {
                if(!T_after.empty())
                    T_after.pop_back();
            } else {
                T_after.emplace_back(c);
            }
        }
        if(T_after.size() != S_after.size()) return false;
        for(int i = 0 ; i < T_after.size(); ++i) {
            if(T_after[i] != S_after[i]) return false;
        }
        return true;
    }
};