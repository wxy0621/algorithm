// 找到字符串中所有字母异位词
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s1 = s.size(), s2 = p.size();
        if (s1 < s2) return {};
        vector<int> s_vec(26, 0), p_vec(26, 0);
        vector<int> res;
        for (int i = 0; i < s2; ++i) {
            ++s_vec[s[i] - 'a'];
            ++p_vec[p[i] - 'a'];
        }
        if (s_vec == p_vec) res.emplace_back(0);
        for (int i = s2; i < s1; ++i) {
            ++s_vec[s[i] - 'a'];
            --s_vec[s[i-s2] - 'a'];
            if (s_vec == p_vec) res.emplace_back(i-s2+1);
        }
        return res;
    }
};