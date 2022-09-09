// 增减字符串匹配
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        int m = 0, n = S.size();
        for(int i = 0; i < S.size(); ++i) {
            if(S[i] == 'I') res.emplace_back(m++);
            else if(S[i] == 'D') res.emplace_back(n--);
        }
        res.emplace_back(n);
        return res;
    }
};