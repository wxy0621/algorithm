// 复原 IP 地址
// 回溯
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> temp;
        backTracking(s, res, temp);
        return res;
    }
    void backTracking(string s, vector<string>& res, vector<string> temp) {
        if (s.size() == 0 && temp.size() == 4) {
            res.emplace_back(vector2String(temp));
        }
        int n = s.size();
        for (int i = 1; i <= n; ++i) {
            if (i > 1 && s[0] == '0') break;
            int val = stoi(s.substr(0, i));
            if (val > 255) break;
            temp.emplace_back(s.substr(0, i));
            backTracking(s.substr(i), res, temp);
            temp.pop_back();
        }
    }
    string vector2String(vector<string>& input) {
        string res;
        for (int i = 0; i < 3; ++i) {
            res += input[i];
            res += ".";
        }
        res += input[3];
        return res;
    }
};