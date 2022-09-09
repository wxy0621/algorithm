// 密钥格式化
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int n = s.size();
        int count = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '-') continue;
            res += toupper(s[i]);
            ++count;
            if (count % k == 0) {
                res += '-';
            }
        }
        reverse(res.begin(), res.end());
        if (res.size() != 0 && res[0] == '-') return res.substr(1, res.size() - 1);
        return res;
    }
};