// 查找常用字符
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        char min_m[26] = {0};
        for(auto& c: A[0]) ++min_m[c - 'a'];
        for(int i = 1; i < A.size(); ++i) {
            char temp[26] = {0};
            for(auto& c: A[i]) ++temp[c - 'a'];
            for(int i = 0; i < 26; ++i) {
                min_m[i] = min(min_m[i], temp[i]);
            }
        }
        for(int i = 0; i < 26; ++i) {
            while(min_m[i]--) {
                string s;
                s += 'a' + i;
                res.emplace_back(s);
            }
        }
        return res;
    }
};